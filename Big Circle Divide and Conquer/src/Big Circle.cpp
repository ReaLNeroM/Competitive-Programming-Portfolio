#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

std::vector<std::pair<double, double> > p;

double euclidd(std::pair<double, double> a, std::pair<double, double> b){
    return std::sqrt(b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

double Dist(int start, int end){
    if(start >= end - 3){
        double min = 1000000000;
        for(int i = start; i <= end; i++){
            for(int j = i + 1; j <= end; j++){
                min = std::min(min, euclidd(p[i], p[j]));
            }
        }

        return min;
    }

    int mid = start + (end - start) / 2;

    double min = std::min(Dist(start, mid), Dist(mid, end));

    std::vector<std::pair<double, double> > midp;
    for(int i = start; i <= end; i++){
        if(std::abs(p[i].second - p[mid].second)<= min){
            std::swap(p[i].first, p[i].second);
            midp.push_back(p[i]);
            std::swap(p[i].first, p[i].second);
        }
    }

    std::sort(midp.begin(), midp.end());

    for(int i = 0; i < midp.size() - 1; i++){
        for(int j = i + 1; j < midp.size() and midp[j].second - midp[i].second <= min; j++){
            min = std::min(min, euclidd(midp[i], midp[j]));
        }
    }

    return min;
}

int main() {
	std::ios::sync_with_stdio(false);
    int points;
    std::cin >> points;

    p.resize(points);
    for(int i = 0; i < points; i++){
    	std::cin >> p[i].first >> p[i].second;
    }

    std::sort(p.begin(), p.end());

    std::cout.precision(2);
    std::cout << std::fixed << Dist(0, points);
    return 0;
}
