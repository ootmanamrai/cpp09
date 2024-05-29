#include "Bureaucrat.hpp"

int main()
{
    try
    {
    Bureaucrat bur("rh", 3);
    int i = 3;
    while (--i)
        bur.increment();
    bur.decrement();
    std::cout << bur;
    std::cout << "copy test" << std::endl;
    Bureaucrat b(bur);
    std::cout << b;
    }

    catch (const std::exception &e)
    {
        std::cout << "catch exception:" << e.what() << std::endl;
    }
}
