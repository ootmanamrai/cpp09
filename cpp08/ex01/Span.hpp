#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private :
    unsigned int max_size;
    unsigned int size;
    std::vector<int> array;
    public :
    Span(const Span &s);
    ~Span();
    Span & operator=(const Span & s);
    void addNumber(int nb);
    unsigned int get_max_size() const ;
    unsigned int get_size() const ;
     int  shortestSpan();
    int  longestSpan();
    Span(unsigned int nb);
    Span();
	void	addRange(std::vector<int>::iterator begin,std::vector<int>::iterator end)
	{
		while (begin != end)
		{
		    addNumber(*begin);
			 begin++;
		}
	}
};
#endif