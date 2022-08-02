#pragma once
#include <random>
namespace crae
{
	inline void seedRandom(int seed) { srand(seed); }

	inline int random() { return rand(); }
	inline int random(int max) { return random() % max; } //exclusive (max = 10) 0 -> 9 | to be inclusive (1-10) +1
	inline int random(int min, int max) { return min + random() % ((max - min) + 1); } //inclusive

	inline float randomf() { return rand() / (float)RAND_MAX; } // 0 - 1
	inline float randomf(float max) { return randomf() * max; }
	inline float randomf(float min, float max) { return min + randomf(max - min); }

}