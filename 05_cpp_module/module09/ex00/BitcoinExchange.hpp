#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <map>
# include <fstream>
# include <string>

class BitcoinExchange
{
private:
	std::map< std::string, double> _DB;

public:
	BitcoinExchange(char* file);
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator=(const BitcoinExchange& ref);
	~BitcoinExchange();
	bool validData(std::string data);
	void execute(char* file);
};

#endif
