#include "Serialization.hpp"

int main() {
    Data d;
    d.age = 42;
    d.name = "Poghos";

    uintptr_t raw = Serialization::serialize(&d);

    Data* ptr = Serialization::deserialize(raw);

    std::cout << "Original pointer: " << &d << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Equal? " << (ptr == &d ? "yes" : "no") << std::endl;

    return 0;
}
