#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main()
{
    std::cout << "----vector container------\n";
    try {
        int nb[] = {5, 6, 7, 88, 9};
        std::vector<int> vec(nb , nb + 5);
        std::cout << *easyfind(vec , 6) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "----list container------\n";
    try {
        int nb[] = {5, 6, 7, 88, 9};
        std::list<int> lst(nb , nb + 5);
        std::cout << *easyfind(lst , 88) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "----deque container------\n";
    try {
        int nb[] = {5, 6, 7, 88, 9};
        std::deque<int> deq(nb , nb + 5);
        std::cout << *easyfind(deq, 10) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
}