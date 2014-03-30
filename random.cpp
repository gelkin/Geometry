#include "random.h"

std::uniform_real_distribution<double> Random::unif = std::uniform_real_distribution<double>(0,1);
std::default_random_engine Random::rand_engine;

double Random::nextDouble(double lower_bound, double upper_bound)
{
    return lower_bound + (upper_bound - lower_bound) * unif(rand_engine);
}
