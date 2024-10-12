#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility> 
#include <string>

class PmergeMe {
public:
    std::vector<int> parseInput(int argc, char* argv[]);
    std::vector<std::pair<int, int> > pairAndSort(const std::vector<int>& numbers);
    void SortedVector(std::vector<int>& sortedList, const std::vector<std::pair<int, int> >& pairs);
    void SortedDeque(std::deque<int>& sortedList, const std::vector<std::pair<int, int> >& pairs);
    
    template<typename Container>
    void displayContainer(const Container& container, const std::string& label);
    
    void measureSortingTime(const std::vector<int>& numbers);
};

#endif 
