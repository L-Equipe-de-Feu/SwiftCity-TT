#ifndef RANDOMENG_H
#define RANDOMENG_H

#include <random>
namespace randEng {
	extern std::random_device r;
	extern std::default_random_engine gen;
}

#endif // !randomEng
