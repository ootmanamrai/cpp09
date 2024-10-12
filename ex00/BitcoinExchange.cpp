#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    std::cout << "Bitcoin Exchange copy assignment" << std::endl;
    if (this != &other)
    {
        this->_database = other._database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        float rate;

        if (std::getline(ss, date, ',') && (ss >> rate)) {
            _database[date] = rate;
        }
    }
    file.close();
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ') {
        return false;
    }
    int year, month, day;
    std::stringstream ss;
    ss << date.substr(0, 4) << " " << date.substr(5, 2) << " " << date.substr(8, 2);
    ss >> year >> month >> day;

    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    if (month == 2) {
        if (isLeapYear(year) && day > 29) return false;
        if (!isLeapYear(year) && day > 28) return false;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false; 
    } else if (day > 31) {
        return false;
    }

    return true;
}


std::map<std::string, float>::const_iterator BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if (it == _database.end() || it->first != date) {
        if (it != _database.begin()) {
            --it;
        }
    }
    return it;
}


void BitcoinExchange::processLine(const std::string& line) const {
    std::stringstream ss(line);
    std::string date, valueStr;


    if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr) || date.empty() || valueStr.empty()) {
        throw std::runtime_error("Error: bad input format => " + line);
    }
    if (!isValidDate(date) || valueStr.find_first_not_of(' ') > 1) {
        throw std::runtime_error("Error: bad input => " + line);
    }
    float value;
    std::stringstream valueStream(valueStr);
    if (!(valueStream >> value)) {
        throw std::runtime_error("Error: invalid number => " + valueStr);
    }
    valueStream >> std::ws;
      if (valueStream.peek() != EOF) {
        throw std::runtime_error("Error: extra unexpected data => " + valueStr);
    }
    if (value < 0) {
        throw std::runtime_error("Error: not a positive number.");
    } else if (value > 1000) {
        throw std::runtime_error("Error: too large a number.");
    }
    std::map<std::string, float>::const_iterator it = findClosestDate(date);
    float rate = it->second;
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        try {
            processLine(line);
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}
