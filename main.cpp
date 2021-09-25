#include <iostream>
#include <random>
#include <cmath>

int main(int argc, char *argv[])
{
  using real = float;
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  std::uniform_real_distribution<real> dist(1.0f-1.0f/(1u<<16), 1.0f);

  int count=0;
  unsigned long long TRIAL = (1ull<<20);
  for (unsigned long long i = 0; i < TRIAL; i++)
  {
    auto v = dist(engine);
    if (v==1){
      ++count;
    }
  }
  if (count==0 ){
      std::cout << "no max value" << std::endl;
  } else {
      std::cout << (std::log2(TRIAL)-std::log2(count)) << std::endl;
  }
  return 0;
}