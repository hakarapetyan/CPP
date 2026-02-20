#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serialization
{
    private:
    Serialization();
    Serialization(const Serialization &other);
    Serialization& operator=(const Serialization &oth);
    
    public:
    ~Serialization();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
#endif