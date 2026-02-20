#include "iter.hpp"

void printInt(const int &x) {
    std::cout << x << " ";
}

void addOne(int &x) {
    x += 1;
}

void printString(const std::string &s) {
    std::cout << s << " ";
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};

    std::cout << "Original ints: ";
    iter(nums, 5, printInt);
    std::cout << std::endl;

    iter(nums, 5, addOne);

    std::cout << "After addOne: ";
    iter(nums, 5, printInt);
    std::cout << "\n\n";

    const int constNums[] = {10, 20, 30};
    std::cout << "Const ints: ";
    iter(constNums, 3, printInt);
    std::cout << "\n\n";

    std::string words[] = {"hello", "world", "iter"};
    std::cout << "Strings: ";
    iter(words, 3, printString);
    std::cout << std::endl;

    return 0;
}


