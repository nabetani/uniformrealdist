#include <iostream>
#include <random>
#include <cmath>
#include <cstdio>
#include <utility>

int main(int argc, char *argv[])
{
    using real = float;
    std::random_device seed_gen;
    std::mt19937_64 rng(seed_gen());
    // real delta = real(1.0 / (1ull << 45));
    // real mid = 5.0/3;
    // real maxval = mid + delta;
    // real minval = mid - delta;
    real minval = -1;
    real maxval = -1.0f/(1ull<<25);
    std::cout << "["<<minval<<", "<<maxval<<")\n";
    std::uniform_real_distribution<real> dist(minval, maxval);

    int eqmax_count = 0;
    int eqmin_count = 0;
    int larger_count = 0;
    int smaller_count = 0;
    std::pair<real,real> range{maxval,minval};
    unsigned long long TRIAL = (1ull << 28);
    for (unsigned long long i = 0; i < TRIAL; i++)
    {
        auto v = dist(rng);
        range.first = std::min(range.first,v);
        range.second = std::max(range.second,v);
        if (v == maxval)
        {
            ++eqmax_count;
        }
        if (v == minval)
        {
            ++eqmin_count;
        }
        if (maxval < v)
        {
            ++larger_count;
        }
        if (v < minval)
        {
            ++smaller_count;
        }
    }
    printf("eqmax_count:%d  eqmin_count:%d  larger_count:%d  smaller_count:%d  range:%e..%e\n",
           eqmax_count,
           eqmin_count,
           larger_count,
           smaller_count,
           range.first, range.second);
    return 0;
}