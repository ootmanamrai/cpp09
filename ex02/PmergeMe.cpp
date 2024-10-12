#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <ctime> 
#include <climits>
#include <cerrno>


std::vector<int> PmergeMe::parseInput(int argc, char* argv[]) {
    std::vector<int> numbers;

    for (int i = 1; i < argc; ++i) {
        char* endPtr; 
        errno = 0; 

        long value = strtol(argv[i], &endPtr, 10); 
      
        if (errno == ERANGE || *endPtr != '\0' || endPtr == argv[i]) {
            throw std::invalid_argument("Invalid input: not a valid integer.");
        }
        if (value <= 0 || value > INT_MAX) {
            throw std::invalid_argument("All input numbers must be positive integers within the range of int.");
        }

        numbers.push_back(static_cast<int>(value)); 
    }
    
    return numbers;
}


std::vector<std::pair<int, int> > PmergeMe::pairAndSort(const std::vector<int>& numbers) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            pairs.push_back(std::make_pair(std::min(numbers[i], numbers[i + 1]), std::max(numbers[i], numbers[i + 1])));
        } 
        else {
            pairs.push_back(std::make_pair(numbers[i], numbers[i])); // Pair with itself
        }
    }
    return pairs;
}

void PmergeMe::SortedVector(std::vector<int>& sortedList, const std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        
        std::vector<int>::iterator pos = std::lower_bound(sortedList.begin(), sortedList.end(), pairs[i].first);
        sortedList.insert(pos, pairs[i].first);

        pos = std::lower_bound(sortedList.begin(), sortedList.end(), pairs[i].second);
        sortedList.insert(pos, pairs[i].second);
    }
}

void PmergeMe::SortedDeque(std::deque<int>& sortedList, const std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
      
        std::deque<int>::iterator pos = std::lower_bound(sortedList.begin(), sortedList.end(), pairs[i].first);
        sortedList.insert(pos, pairs[i].first);

        pos = std::lower_bound(sortedList.begin(), sortedList.end(), pairs[i].second);
        sortedList.insert(pos, pairs[i].second);
    }
}

template<typename Container>
void PmergeMe::displayContainer(const Container& container, const std::string& label) {
    std::cout << label << ": ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::measureSortingTime(const std::vector<int>& numbers) {

    std::vector<int> sortedVector;
    std::vector<std::pair<int, int> > pairs = pairAndSort(numbers);
    
    clock_t startVector = clock();
    SortedVector(sortedVector, pairs);
    clock_t endVector = clock();
    

    std::deque<int> sortedDeque;
    clock_t startDeque = clock();
    SortedDeque(sortedDeque, pairs);
    clock_t endDeque = clock();
    

    displayContainer(numbers, "Before");
    displayContainer(sortedVector, "After sorting with std::vector");
    displayContainer(sortedDeque, "After sorting with std::deque");
    
    double timeVector = double(endVector - startVector) / CLOCKS_PER_SEC * 1e6; 
    double timeDeque = double(endDeque - startDeque) / CLOCKS_PER_SEC * 1e6;
    
    std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector: " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() << " elements with std::deque: " << timeDeque << " us" << std::endl;
}
