#include "Random.h"

#include <random>

namespace SBF {
std::random_device g_random_device;
std::mt19937_64 g_random_number_engine(g_random_device());
std::uniform_int_distribution<int> g_random_int_generator;

int GetRandomInt(int min, int max) {
  int r = g_random_int_generator(g_random_number_engine);
  return r % (max - min + 1) + min;
}
}  // End namespace SBF
