/**
 * @file    ProbablilityCalculator.hpp
 * @author  LaverWinEmpty@google.com
 * @brief   probablility calculator
 * @version 1.0
 * @date    2024-02-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LWE__PROBABLITIY_CALCULATOR_HPP__
#define LWE__PROBABLITIY_CALCULATOR_HPP__

#include "math.h"

#ifndef IN
#    define IN
#endif

#ifndef OUT
#    define OUT
#endif

class ProbabilityCalculator
{
public:
    struct Probability;
    struct Percent;

private:
    struct Type
    {
        Type(IN double);
        operator double() const;
        double n;
    };

public:
    struct Probability: Type
    {
        Probability(IN double = 0);
        Percent ToPercent() const;
    };

    struct Percent: Type
    {
        Percent(IN double = 0);
        Probability ToProbability() const;
    };

public:
    // number of case
    ProbabilityCalculator(IN double cases, IN double target);

    // percent
    ProbabilityCalculator(IN double);

public:
    ProbabilityCalculator();

public:
    void Setpercent(IN Percent);
    void SetProbability(IN Probability);

public:
    Percent     GetPercent() const;
    Probability GetProbability() const;

public:
    /**
     * @brief binomial distribution
     * @note  recommended maximum: 1029
     *
     * @param count  [in] try count
     * @param target [in] target count
     * @return Percent
     */
    Percent BinomialDistribution(IN int count, IN int target) const;

    /**
     * @brief calculate success rate by try count
     * @note  maximum: 1029
     *
     * @param int [in] try count
     * @return Percent
     */
    Percent Try(IN int) const;

private:
    double successRate;
};

#endif