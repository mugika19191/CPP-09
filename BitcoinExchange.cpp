#include "BitcoinExchange.hpp"
#include <cctype>
#include <string>
#include <fstream>


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	std::string line;
	std::string date;
	std::string num;
	std::ifstream MyFile(file);
	while (getline(MyFile, line)) {
		
		date = line.substr(0, line.find(','));
		num = line.substr(line.find(',') + 1);
		data[date] = atof(num.c_str());
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

#include <string>
#include <cctype>
#include <cstdlib>

bool isLeapYear(int year)
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool isValidDate(const std::string &date)
{
    // Format must be YYYY-MM-DD (10 chars)
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // Check all numeric positions
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year <= 0)
        return false;
    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Handle leap year
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}


float BitcoinExchange::getValue(std::string date)
{
	if (isValidDate(date))
	{
		std::cout << "date is good!" << std::endl;
		std::map<std::string, float>::iterator it = data.lower_bound(date);
		if (it != data.end() && it->first == date)
		{
			std::cout << "nothing to do" << std::endl;
		}
		else
		{
			if (it == data.begin())
			{
				std::cerr << "Error: no earlier data available for date: " << date << "\n";
				return (0.0f);
			}
			else
				--it;
		}
		return (it->second);
	}
	return (0.0f);
}
