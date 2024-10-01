#include "Span.hpp"

Span::~Span()
{

}

unsigned int	Span::get_max_size() const
{
	return this->max_size;
}

unsigned int	Span::get_size() const
{
	return this->size;
}

Span::Span(const Span & s)
{
	this->array = s.array;
	this->max_size = s.get_max_size();
	this->size = s.get_size();
}

Span & Span::operator=(const Span &s)
{
	this->array = s.array;
	this->max_size = s.get_max_size();
	this->size = s.get_size();
	return *this;
}

Span::Span(unsigned int range) : max_size(range) , size(0)
{
    if(max_size == 0)
        throw std::runtime_error("span Can't create array of 0");
}

void Span::addNumber(int nb)
{
    if(size == max_size)
        throw std::runtime_error("Span : Cannot add more numbers");
    size++;
    array.push_back(nb);
}

int Span::shortestSpan()
{
    if(size < 2)
        throw std::runtime_error("Span: Not enough numbers to find a span");

    std::sort(array.begin(), array.end());
    int min = __INT_MAX__;
    for(unsigned int i = 0; i < size - 1; i++)
    {
        if(array[i + 1] - array[i] < min)
            min = array[i + 1] - array[i];
    }
    return (min);
}

int Span::longestSpan()
{
    if(size < 2)
        throw std::runtime_error("Span: Not enough numbers to find a span");
    
    int minVal = *std::min_element(array.begin(), array.end());
    int maxVal = *std::max_element(array.begin(), array.end());
    
    return maxVal - minVal;
}

