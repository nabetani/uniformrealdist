#include <iostream>
#include <random>
#include <cmath>
#include <cstdio>
#include <utility>

int main(int argc, char *argv[])
{
  using real = float;
  std::mt19937_64 rng(0);
  constexpr real d0 = 1e-36;
  constexpr real d1 = d0 * (1ull << 22);
  real minval = -d1 * 16;
  real maxval = d1 + d0;
  std::cout << "[" << minval << ", " << maxval << ")\n";
  std::uniform_real_distribution<real> dist(minval, maxval);
  constexpr unsigned long long TRIAL = 1ull << 28;
  for (unsigned long long i = 0; i < TRIAL; i++)
  {
    auto v = dist(rng);
    if (v < minval || maxval < v)
    {
      std::printf("v=%.10e  range is [%.10e, %.10e)\n", v, minval, maxval);
      return 0;
    }
  }
  std::puts("No unexpected values were found.");
  return 0;
}