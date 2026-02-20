#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iterator>
#include <cstdlib>

class Span
{
private:
  unsigned int N;
  std::vector<int> cont;

public:
    Span();
    ~Span();
    Span(const Span &other);
    Span(unsigned int num);
    Span& operator=(const Span &other);
    void addNumber(const int num);
    size_t shortestSpan() const;
    size_t longestSpan() const;
    template <typename it>
     void addRange(it begin, it end)
    {
     if(std::distance(begin,end) + cont.size() > N)
      throw std::length_error("Cannot add number: Span capacity exceeded");   
       cont.insert(cont.end(), begin, end); 
    }
};

#endif