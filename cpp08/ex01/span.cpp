#include "span.hpp"

Span ::Span():N(0){}

Span::~Span(){}

Span::Span(const Span& other)
{
    this->N=other.N;
}

Span& Span ::operator=(const Span &other)
{
    if(this!=&other)
    {
        this->N=other.N;
    }
    return(*this);
}

Span::Span(unsigned int num)
{
    this->N = num;
}

void Span:: addNumber(int num)
{
    if(cont.size() >= N)
        throw std::length_error("Cannot add number: Span capacity exceeded");
    cont.push_back(num);
}
size_t Span::longestSpan() const
{
    if (cont.size() < 2)
    throw std::logic_error("Not enough numbers (less than 2) to compute a span");
    
    int max = *std::max_element(cont.begin(),cont.end());
    int min = *std::min_element(cont.begin(),cont.end());

    size_t dif =static_cast<size_t>(max) - static_cast<size_t>(min);
    if (dif > INT_MAX)
    {
        std::cout<<"Value is equal to or greater than INT_MAX"<<std::endl;
        return (INT_MAX);
    }
    return(dif);
}

size_t Span::shortestSpan() const
{
    if (cont.size() < 2)
        throw std::logic_error("Not enough numbers (less than 2) to compute a span");

    std::vector<int> cont2 = cont;
    std::sort(cont2.begin(),cont2.end());
    size_t dif;
    size_t shortest = INT_MAX;
    for(size_t i = 1; i < cont2.size(); i++)
    {
        dif = static_cast<size_t>(cont2[i]) - static_cast<size_t>(cont2[i-1]);
        if(dif<shortest)
            shortest =dif;
    }
    if(shortest == INT_MAX)
        std::cout<<"Value is equal to or greater than INT_MAX"<<std::endl;
    return(shortest);
}

