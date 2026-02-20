#include "MutantStack.hpp"
#include "list"

void testContainer(MutantStack<int> &container) {
    container.push(5);
    container.push(17);
    container.push(3);
    container.push(5);
    container.push(737);
    container.push(0);

    for (MutantStack<int>::it it = container.begin(); it != container.end(); ++it)
        std::cout << *it << std::endl;
}

void testContainer(std::list<int> &container) {
    container.push_back(5);
    container.push_back(17);
    container.push_back(3);
    container.push_back(5);
    container.push_back(737);
    container.push_back(0);

    for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << std::endl;
}


int main() {
    std::cout << "Testing MutantStack:" << std::endl;
    MutantStack<int> mstack;
    testContainer(mstack);

    std::cout << "\nTesting std::list:" << std::endl;
    std::list<int> lst;
    testContainer(lst);

    return 0;
}
// int main()
// {
// std::list<int> mstack;
// mstack.push_back(5);
// mstack.push_back(17);
// std::cout << mstack.back() << std::endl;
// mstack.pop_back();
// std::cout << mstack.size() << std::endl;
// mstack.push_back(3);
// mstack.push_back(5);
// mstack.push_back(737);

// mstack.push_back(0);
// std::list<int>::iterator it = mstack.begin();
// std::list<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::list<int> s(mstack);
// return 0;
// }


// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << "Top element: " << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << "Size after pop: " << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     std::cout << "Iterating through MutantStack:" << std::endl;
//     for (MutantStack<int>::it it = mstack.begin(); it != mstack.end(); ++it)
//         std::cout << *it << std::endl;

//     std::cout << "Reverse iterating:" << std::endl;
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
//         std::cout << *rit << std::endl;

//     std::stack<int> s(mstack);

//     return 0;
// }


