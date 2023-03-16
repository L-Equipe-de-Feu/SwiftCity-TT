#ifndef RANDOMENGINE_H
#define RANDOMENGINE_H

#include <random>
std::random_device r;
std::default_random_engine gen(r());

#endif