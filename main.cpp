#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

/*bool process_line(std::string line){
	
}*/
#include "BitcoinExchange.hpp"


int main(int count , char **args){

	BitcoinExchange *bit;
	std::string date;
	std::string num;
	std::string line;

	if (count != 2){
			std::cout << "Just one param!" << std::endl;
			return 1;
		}
	bit = new BitcoinExchange("data.csv");
	std::ifstream MyFile(args[1]);
	while (getline(MyFile, line)) {
		
		date = line.substr(0, line.find('|'));
		date.pop_back();
		num = line.substr(line.find('|') + 1);
		std::cout << date << std::endl;
		std::cout.precision(2);
		std::cout << bit->getValue(date) << std::endl;
		std::cout << bit->getValue(date) * atof(num.c_str()) << std::endl;
		//falta por mirar si en numero se pasa de largo o no
		//si es 0 por falta de valores, tambien habria que pritear otra cosa
	}

	delete (bit);
	return 0;
}