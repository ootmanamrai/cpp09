#include "BitcoinExchange.hpp"

// Function to load the database from a CSV file
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

// Helper function to validate the date format "YYYY-MM-DD"
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ') {
        return false;
    }
    int year, month, day;
    std::stringstream ss;
    ss << date.substr(0, 4) << " " << date.substr(5, 2) << " " << date.substr(8, 2);
    ss >> year >> month >> day;

    // Validate month and day
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    // Check for month-end validation
    if (month == 2) {
        // February: check for 28 or 29 days
        if (isLeapYear(year) && day > 29) return false;
        if (!isLeapYear(year) && day > 28) return false;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false; // April, June, September, November have 30 days
    } else if (day > 31) {
        return false; // All other months have 31 days
    }

    return true;
}

// Function to find the closest date
std::map<std::string, float>::const_iterator BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if (it == _database.end() || it->first != date) {
        if (it != _database.begin()) {
            --it;
        }
    }
    return it;
}

// Function to process a single line from the input
void BitcoinExchange::processLine(const std::string& line) const {
    std::stringstream ss(line);
    std::string date, valueStr;

    // Check for format "date | value" with spaces around '|'
    if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr) || date.empty() || valueStr.empty()) {
        throw std::runtime_error("Error: bad input format => " + line);
    }
    // Validate the date format
    if (!isValidDate(date) || valueStr.find_first_not_of(' ') > 1) {
        throw std::runtime_error("Error: bad input => " + line);
    }
    // Convert the value to a float
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
    // Find the closest date in the database
    std::map<std::string, float>::const_iterator it = findClosestDate(date);
    float rate = it->second;
    // Output the result
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

// Function to process the input file
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btcExchange;
        // Load the Bitcoin exchange rates from the CSV file
        btcExchange.loadDatabase("data.csv");

        // Process the input file to calculate Bitcoin values
        btcExchange.processInputFile(argv[1]);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}