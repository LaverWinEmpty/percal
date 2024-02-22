#include "ProbablilityCalculator.hpp"
#include "iostream"

ProbabilityCalculator::Type::Type(double param): n(param < 0 ? 0 : param) {}

ProbabilityCalculator::Type::operator double() const
{
    return n;
}

ProbabilityCalculator::Probability::Probability(double param): Type(param > 1 ? 1 : param) {}

ProbabilityCalculator::Percent ProbabilityCalculator::Probability::ToPercent() const
{
    return n * 100;
}

ProbabilityCalculator::Percent::Percent(double param): Type(param > 100 ? 100 : param) {}

ProbabilityCalculator::Probability ProbabilityCalculator::Percent::ToProbability() const
{
    return n * 0.01;
}

ProbabilityCalculator::ProbabilityCalculator(double cases, double target): successRate(target / cases)
{
    if(successRate > 1) {
        successRate = 1;
    }
    else if(successRate < 0) {
        successRate = 0;
    }
}

ProbabilityCalculator::ProbabilityCalculator(double param): successRate(param * 0.01)
{
    if(successRate > 1) {
        successRate = 1;
    }
    else if(successRate < 0) {
        successRate = 0;
    }
}

ProbabilityCalculator::ProbabilityCalculator(): successRate(0) {}

void ProbabilityCalculator::Setpercent(Percent param)
{
    successRate = param.ToProbability();
}

void ProbabilityCalculator::SetProbability(Probability param)
{
    successRate = param;
}

ProbabilityCalculator::Percent ProbabilityCalculator::GetPercent() const
{
    return successRate * 100;
}

ProbabilityCalculator::Probability ProbabilityCalculator::GetProbability() const
{
    return successRate;
}

ProbabilityCalculator::Percent ProbabilityCalculator::BinomialDistribution(int tryCount, int targetCount) const
{
    double failureRate  = 1 - successRate;
    double failureCount = static_cast<double>(tryCount) - static_cast<double>(targetCount);

    // factorial
    double binomialCoefficient = exp(lgamma(tryCount + 1) - (lgamma(targetCount + 1) + lgamma(failureCount + 1)));

    // to percent
    return binomialCoefficient * pow(successRate, targetCount) * pow(failureRate, failureCount) * 100;
}

ProbabilityCalculator::Percent ProbabilityCalculator::Try(int count) const
{
    double result = 0;
    for(int i = 1; i <= count; ++i) {
        result += BinomialDistribution(count, i);
    }
    return result;
}