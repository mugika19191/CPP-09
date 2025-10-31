#include <map>
#include <string>
#include <iostream>

class BitcoinExchange
{
	public:
		std::map <std::string, float> data;
		BitcoinExchange();
		BitcoinExchange(std::string file);
		~BitcoinExchange();
		float getValue(std::string date);
};