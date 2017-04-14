#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e2;

struct hor_line {
    int y;
    int x1, x2;
    bool operator<(hor_line const &z) const {
        return y < z.y;
    }
};
struct ver_line {
    int x;
    int y1, y2;
    bool operator<(ver_line const &z) const {
        return x < z.x;
    }
};
hor_line make_h(int y, int x1, int x2){
    hor_line hh;
    hh.y = y;
    hh.x1 = x1;
    hh.x2 = x2;
    return hh;
}
ver_line make_v(int x, int y1, int y2){
    ver_line vv;
    vv.x = x;
    vv.y1 = y1;
    vv.y2 = y2;
    return vv;
}

bool contains(ver_line ver, int y, int x){
    if(ver.x == x and ver.y1 <= y and y <= ver.y2){
        return true;
    }
    return false;
}
bool contains(hor_line hor, int y, int x){
    if(hor.y == y and hor.x1 <= x and x <= hor.x2){
        return true;
    }
    return false;
}
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){
		return a.second <= b.second;
	} else {
		return a.first <= b.first;
	}
}
int x[maxn], y[maxn], l[maxn];
int res = 0;

vector<hor_line> h;
vector<ver_line> v;

vector<pair<int, int>> v_enter, v_exit;
vector<pair<int, int>> h_enter, h_exit;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> l[i];
        v_enter.push_back({x[i], y[i]});
        v_exit.push_back({x[i], y[i] + l[i]});
        v_enter.push_back({x[i] + l[i], y[i]});
        v_exit.push_back({x[i] + l[i], y[i] + l[i]});

        h_enter.push_back({y[i], x[i]});
        h_exit.push_back({y[i], x[i] + l[i]});
        h_enter.push_back({y[i] + l[i], x[i]});
        h_exit.push_back({y[i] + l[i], x[i] + l[i]});
    }

    int enter_pos = 0, exit_pos = 0;

    int balance = 0;
    int last = -1;

    sort(v_enter.begin(), v_enter.end(), cmp);
    sort(v_exit.begin(), v_exit.end(), cmp);
    while(exit_pos != v_exit.size()){
        if(enter_pos != v_enter.size() and cmp(v_enter[enter_pos], v_exit[exit_pos])){
            if(balance == 0){
                last = v_enter[enter_pos].second;
            }
            balance++;
            enter_pos++;
        } else {
            balance--;
            if(balance == 0){
                v.push_back(make_v(v_exit[exit_pos].first, last, v_exit[exit_pos].second));
            }
            exit_pos++;
        }
    }

    enter_pos = exit_pos = 0;
    sort(h_enter.begin(), h_enter.end(), cmp);
    sort(h_exit.begin(), h_exit.end(), cmp);
    while(exit_pos != h_exit.size()){
        if(enter_pos != h_enter.size() and cmp(h_enter[enter_pos], h_exit[exit_pos])){
            if(balance == 0){
                last = h_enter[enter_pos].second;
            }
            balance++;
            enter_pos++;
        } else {
            balance--;
            if(balance == 0){
                h.push_back(make_h(h_exit[exit_pos].first, last, h_exit[exit_pos].second));
            }
            exit_pos++;
        }
    }

    set<pair<pair<int, int>, int>> s;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < h.size(); j++){
        	for(int k = i + 1; k < v.size(); k++){
				for(int l = j + 1; l < h.size(); l++){
					if(h[l].y - h[j].y > 0 and v[k].x - v[i].x > 0 and
							h[l].y - h[j].y == v[k].x - v[i].x and
							contains(v[i], h[j].y, v[i].x) and
							contains(v[i], h[l].y, v[i].x) and
							contains(v[k], h[j].y, v[k].x) and
							contains(v[k], h[l].y, v[k].x) and
							contains(h[j], h[j].y, v[i].x) and
							contains(h[j], h[j].y, v[k].x) and
							contains(h[l], h[l].y, v[i].x) and
							contains(h[l], h[l].y, v[k].x)){
						s.insert({{h[j].y, v[i].x}, h[l].y - h[j].y});
					}
				}
			}
		}
    }

    cout << s.size();
}
