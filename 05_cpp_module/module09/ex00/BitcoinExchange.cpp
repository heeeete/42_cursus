#include "BitcoinExchange.hpp"

bool BitcoinExchange::validData(std::string data){
	size_t idx;
	size_t curIdx = 0;

	if ((idx = data.find(',')) == std::string::npos) return false;

	std::string date = data.substr(0,idx);
	std::string value = data.substr(idx + 1, data.length());
	std::string Y,M,D;
	int tempY = 0;
	int tempM = 0;
	int tempD = 0;

	//year, month, day parse
	for (int i = 0; (idx = date.find('-', curIdx)) != std::string::npos; i++){
			size_t len = idx - curIdx;
			if (i == 0){
				if ((Y = date.substr(curIdx, len)).find_first_not_of("0123456789") != std::string::npos) return false;
				tempY = atoi(Y.c_str());
				if (tempY < 1000 || tempY > 9999)	return false;
			}
			else if (i == 1){
				if ((M = date.substr(curIdx, len)).find_first_not_of("0123456789") != std::string::npos) return false;
				tempM = atoi(M.c_str());
				if (tempM < 1 || tempM > 12) return false;
			}
			curIdx = idx + 1;
	}
	// Day
	if ((D = date.substr(curIdx)).find_first_not_of("0123456789") != std::string::npos) return false;
	tempD = atoi(D.c_str());
	if (tempD < 1 || tempD > 31) return false;
	else if (tempD == 31 && (tempM == 4 || tempM == 6 || tempM == 9 || tempM == 11)) return false;
	if (tempY % 4 == 0 && (tempY % 100 != 0 || tempY % 400 == 0)) {
		if (tempD > 29 && tempM == 2) return false;
	} else if (tempD > 28 && tempM == 2) return false;
	if (tempY == 0 || tempM == 0 || tempD == 0)	return false;

	// value  parse
	char* ptr = NULL;
	double v = std::strtod(value.c_str(), &ptr);
	if (*ptr && strcmp(ptr, "f")) return false;
	else if (v < 0) return false;
	// std::cout << Y << " " << M << " " << D << " " << v << "\n";
	// std::map<std::string, double>::iterator it = _DB.find(date);
	// if (it == _DB.end())
	_DB[date] = v;
	std::cout << _DB[date] << "\n";
	return true;
}

BitcoinExchange::BitcoinExchange(){
	std::ifstream csv("data.csv");
	std::string read;
	int lineIdx = 2;


	if (!csv)
		throw std::runtime_error("Error: could not open data.csv file.");
	else if (std::getline(csv, read).eof())
		throw std::runtime_error("Error: The data.csv file is an empty file.");

	for (; std::getline(csv, read) ;){
		if (read != "date,exchange_rate" && !read.empty()){
			if (!validData(read)){
				std::cout << lineIdx << " Line " << "\"" << read << "\" ";
				throw std::runtime_error("Error: syntex error.");
			}
		}
		lineIdx++;
	}
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref){
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref){
}
BitcoinExchange::~BitcoinExchange(){
}
