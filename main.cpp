#include <cstdio>
#include <random>

int main(int argc, char *argv[])
{
  std::mt19937_64 engine(0);
  auto delta = 1.0/(1ull<<50);
  auto maxval = 1+delta;
  auto minval = 1-delta;
  std::uniform_real_distribution<> dist(minval,maxval);

  constexpr unsigned long long TRIAL = 1ull<<28;
  for (unsigned long long i = 0; i<TRIAL; i++)
  {
    auto v = dist(engine);
    if (v<minval || maxval<=v ){
      std::printf("v=%.17f  range is [%.17f, %.17f)", v, minval, maxval );
      return 0;
    }
  }
  std::puts( "No unexpected values were found." );
  return 0;
}