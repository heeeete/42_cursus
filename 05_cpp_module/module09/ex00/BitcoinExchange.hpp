#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <map>
# include <fstream>
# include <string>
# include <sstream>
# include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string, double> _DB;
public:
	BitcoinExchange();
	BitcoinExchange(char* file, char* csvFile);
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator=(const BitcoinExchange& ref);
	~BitcoinExchange();
	bool validDataCheck(std::string data, std::string sep);
	void validData(std::string data);
	void execute(char* file);
};

#endif
