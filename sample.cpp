#include "iostream"
#include "ProbablilityCalculator.hpp"

// clang-format off

int main()
{
    int tryCnt = 1029;

    ProbabilityCalculator percal(1);

    std::cout << percal.BinomialDistribution(1029, 515) << std::endl;

    std::cout << "Probability: " << percal.GetPercent() << "%" << std::endl;

    std::cout << "Try:" << tryCnt << std::endl;

    std::cout << "Success rate: " << percal.Try(tryCnt) << "%\n";

    return 0;
}