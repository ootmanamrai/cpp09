#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        PmergeMe pmerge;
        std::vector<int> numbers = pmerge.parseInput(argc, argv);
        pmerge.measureSortingTime(numbers);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
