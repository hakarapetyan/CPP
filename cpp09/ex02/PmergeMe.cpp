#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other){(void)other;}
PmergeMe& PmergeMe::operator=(const PmergeMe &other){(void)other; return(*this);}
void PmergeMe::parsing(int argc,char **argv)
{
    for(int i =1; i < argc;i++)
    {
        std::string str(argv[i]);

        for(size_t j =0; j < str.size();j++)
        {
            if(!isdigit(str[j]))
            {
                std::cerr<<"Error: value contains unexpected characters.\n";
                throw std::exception();
            }

        }
        long long x =std::atoll(argv[i]);
        if (x < 0 || x > INT_MAX)
        {
            std::cerr<<"Error: invalid numeric value.\n";
            throw std::exception();
        }
        
        v.push_back((int)x);
        q.push_back((int)x);
    }
}
PmergeMe ::PmergeMe(int argc, char **argv)
{
    parsing(argc,argv);
}
 void PmergeMe::small_big_sort(std::vector<int>& cont,std::vector<int>& big,std::vector<int>& small)
    {
        if (cont.size() < 2)
        {
            big = cont;
            return ;
        }
        for (size_t i = 0;i + 1 < cont.size(); i+=2)
        {
            int s = cont[i];
            int b = cont[i + 1];

            if(s > b)
                std::swap(s,b);
            small.push_back(s);
            big.push_back(b);    
        }
        if (cont.size() % 2 == 1)
            small.push_back(cont.back());
    }
void PmergeMe::small_big_sort(std::deque<int>& cont,std::deque<int>& big,std::deque<int>& small)
{
        if (cont.size() < 2)
        {
            big = cont;
            return ;
        }
        for (size_t i = 0;i + 1 < cont.size(); i+=2)
        {
            int s = cont[i];
            int b = cont[i + 1];

            if(s > b)
                std::swap(s,b);
            small.push_back(s);
            big.push_back(b);    
        }
        if (cont.size() % 2 == 1)
            small.push_back(cont.back());
}
void PmergeMe::MergeInsertSort(std::vector<int> &big, std::vector<int> &small)
{
    for (size_t i = 0; i < small.size(); i++)
    {
        int key =small[i];
        size_t left = 0, right = big.size();

        while (left < right)
        {
            int mid = (right + left) / 2;
                if (key > big[mid])
                    left = mid +1;
                else
                    right = mid;
        }

        big.insert(big.begin() + left, key);
    }
}
void PmergeMe::FordSortVector(std::vector<int> &vect)
{
    if (vect.size() <= 1)
        return ;
    
    std::vector<int> small, big;

    small_big_sort(vect, big,small);

    FordSortVector(big);

    MergeInsertSort(big, small);

    vect = big;
}

void PmergeMe::MergeInsertSort(std::deque<int> &big, std::deque<int> &small)
{
    for (size_t i = 0; i < small.size(); i++)
    {
        int key =small[i];
        size_t left = 0, right = big.size();

        while (left < right)
        {
            int mid = (right + left) / 2;
                if (key > big[mid])
                    left = mid +1;
                else
                    right = mid;
        }

        big.insert(big.begin() + left, key);
    }
}
void PmergeMe::FordSortDeque(std::deque<int> &vect)
{
    if (vect.size() <= 1)
        return ;
    
    std::deque<int> small, big;

    small_big_sort(vect, big,small);

    FordSortDeque(big);

    MergeInsertSort(big, small);

    vect = big;
}
void PmergeMe::run()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::clock_t startV = std::clock();
    std::vector<int> vecCopy = v;
    FordSortVector(vecCopy);
    std::clock_t endV = std::clock();

    std::clock_t startD = std::clock();
    std::deque<int> deqCopy = q;
    FordSortDeque(deqCopy);
    std::clock_t endD = std::clock();

    std::cout<<"After: ";
    for (size_t i = 0; i < vecCopy.size(); i++)
        std::cout << vecCopy[i] << " ";
    std::cout << std::endl;

    double tV = (double)(endV - startV) / CLOCKS_PER_SEC * 1e6;
    double tD = (double)(endD - startD) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : " << tV << " us" << std::endl;

    std::cout << "Time to process a range of " << q.size()
              << " elements with std::deque : " << tD << " us" << std::endl;
}
