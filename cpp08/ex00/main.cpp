#include "easyfind.hpp"


int main() {
    std::vector<int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(10);

    try {
        std::vector<int>::iterator it = easyfind(v, 7);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
