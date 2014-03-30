#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random
{
public:
    static double nextDouble(double lower, double upper);
private:
    static std::uniform_real_distribution<double> unif;
    static std::default_random_engine rand_engine;
};

#endif // RANDOM_H
