#include <bits/stdc++.h>

typedef long long ll;

double clamp_value(double a, double lower_bound){
    return std::max(a, lower_bound);
}

double calculateTotalPayment(int initialLevelOfDebt, int interestPercentage, int repaymentPercentage){
    double depositPaid = clamp_value(initialLevelOfDebt * 0.1, 50);
    double totalDebtLeft = initialLevelOfDebt - depositPaid;
    double fixedInterestAmount = initialLevelOfDebt * (interestPercentage / 100.0);
    double fixedRepaymentAmount = clamp_value(initialLevelOfDebt * (repaymentPercentage / 100.0), 50);

    double repaymentPaid = 0.0;
    for(int i = 0; i < 300; i++){
        if (i == 300){
            return 1e300;
        }

        double variableInterestAmount = std::floor(totalDebtLeft * (interestPercentage / 100.0));
        totalDebtLeft += fixedInterestAmount;
        double variableRepaymentAmount = std::min(
            std::ceil(clamp_value(totalDebtLeft * (repaymentPercentage / 100.0), 50)),
            totalDebtLeft
        );
        repaymentPaid += fixedRepaymentAmount;
        totalDebtLeft -= fixedRepaymentAmount;

        if(totalDebtLeft < 0.00000001){
            break;
        }
    }

    return depositPaid + repaymentPaid;
}

int main(){
    int initialLevelOfDebt, interestPercentage, repaymentPercentage;
    std::cin >> initialLevelOfDebt >> interestPercentage >> repaymentPercentage;

    std::cout << calculateTotalPayment(initialLevelOfDebt, interestPercentage, repaymentPercentage) << '\n';
}
