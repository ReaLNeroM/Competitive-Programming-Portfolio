#include <bits/stdc++.h>

typedef long long ll;

double bestTradingBonus(std::vector<int> trader, std::vector<int> risk, std::vector<int> bonus){
    std::vector<std::pair<int, int>> options(risk.size());

    for(int i = 0; i < risk.size(); i++){
        options[i] = {risk[i], bonus[i]};
    }
    std::sort(options.begin(), options.end());

    std::sort(trader.begin(), trader.end());

    int totalValue = 0;

    int currentOptionPointer = 0;
    int bestAchievableBonus = 0;
    for(int tradingSkill : trader){
        while(currentOptionPointer != options.size() and options[currentOptionPointer].first <= tradingSkill){
            bestAchievableBonus = std::max(bestAchievableBonus, options[currentOptionPointer].second);
            currentOptionPointer++;
        }

        totalValue += bestAchievableBonus;
    }

    return totalValue;
}

int main(){
    int traderCount;
    std::cin >> traderCount;

    std::vector<int> trader(traderCount);
    for(int i = 0; i < traderCount; i++){
        std::cin >> trader[i];
    }

    int optionsCount;
    std::cin >> optionsCount;
    std::vector<int> risk(optionsCount), bonus(optionsCount);
    for(int i = 0; i < optionsCount; i++){
        std::cin >> risk[i];
    }
    for(int i = 0; i < optionsCount; i++){
        std::cin >> bonus[i];
    }

    std::cout << bestTradingBonus(trader, risk, bonus) << '\n';
}
