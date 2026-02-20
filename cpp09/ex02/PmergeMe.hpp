#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
    public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe(int argc, char **argv);
    PmergeMe& operator=(const PmergeMe &other);
    void parsing(int argc,char **argv);
    void small_big_sort(std::vector<int>& cont,std::vector<int>& big,std::vector<int>& small);
    void small_big_sort(std::deque<int>& cont,std::deque<int>& big,std::deque<int>& small);
    void FordSortVector(std::vector<int> &cont);
    void MergeInsertSort(std::vector<int> &big, std::vector<int> &small);
    void FordSortDeque(std::deque<int> &cont);
    void MergeInsertSort(std::deque<int> &big, std::deque<int> &small);
    void run();
    private:
    std::vector<int> v;
    std::deque<int> q;
};
#endif