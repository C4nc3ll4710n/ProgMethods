#include "generators.h"

LCG::LCG(unsigned int s) 
{
    seed(s);
}

void LCG::seed(unsigned int s)
{
    x = s;
}

unsigned int LCG::next_mod(unsigned int modd)
{
    return next_full()%modd;
}

unsigned int LCG::next_full()
{
    x = x * 1664525u + 1013904223u;
    return x;
}