#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    Span sp2(10000);
    std::vector<int> val(10000 ,0);
    for(int i = 0 ; i < 10000; ++i)
        val[i] = i;
    sp2.addRange(val.begin(), val.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    Span sp3(1);
    try
    {
        sp3.shortestSpan();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        sp3.addNumber(55);
        sp3.addNumber(44);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        sp3.shortestSpan();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}