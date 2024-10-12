#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <limits>
#include <algorithm>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

public:
    void loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    std::map<std::string, float>::const_iterator findClosestDate(const std::string& date) const;
    void processLine(const std::string& line) const;
    void processInputFile(const std::string& filename) const;
    bool isLeapYear(int year) const;
};
