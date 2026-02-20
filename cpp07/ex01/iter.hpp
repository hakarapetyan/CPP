#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename I>
void iter(I *p,size_t len, void (*func)(I &x))
{
    for(size_t i=0;i<len;i++)
        func(p[i]);
}
template <typename I>
void iter(const I *p,size_t len, void (*func)(const I &x))
{
    for(size_t i=0;i<len;i++)
        func(p[i]);
}
#endif