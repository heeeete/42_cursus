# include "BitcoinExchange.hpp"
# define INVALID_ERROR 1
# define NOT_IN_SCOPE_VALUE_ERROR 2

void removeWhiteSpace(std::string& str){
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

std::string trimTrailingZeros(double number) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(10) << number;
    std::string str = out.str();
    // 소수점 이하 마지막에 있는 0들을 제거합니다.
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    // 만약 소수점 이하가 0이었다면, 소수점도 제거합니다.
    str.erase(str.find_last_not_of('.') + 1, std::string::npos);
    return str;
}

bool validDate(std::string date){
	size_t idx;
	size_t curIdx = 0;
	std::string Y,M,D;
	int tempY = 0;
	int tempM = 0;
	int tempD = 0;

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
	return true;
}

int validInput(std::string& read){
	size_t idx;
	if ((idx = read.find('|')) == std::string::npos) return INVALID_ERROR;

	std::string date = read.substr(0, idx);
	std::string value = read.substr(idx + 1, read.length());
	removeWhiteSpace(date);
	removeWhiteSpace(value);




	if (!validDate(date))
		return INVALID_ERROR;
	char* ptr = NULL;
	double v = std::strtod(value.c_str(), &ptr);
	if (*ptr && strcmp(ptr, "f")) return INVALID_ERROR;
	else if (v <= 0 || v >= 1000) return NOT_IN_SCOPE_VALUE_ERROR;
	return 0;
}

bool BitcoinExchange::validDataCheck(std::string data){
	size_t idx;

	if ((idx = data.find(',')) == std::string::npos) return false;

	std::string date = data.substr(0,idx);
	std::string value = data.substr(idx + 1, data.length());
	removeWhiteSpace(date);
	//year, month, day parse
	if (!validDate(date))
		return false;

	// value  parse
	char* ptr = NULL;
	double v = std::strtod(value.c_str(), &ptr);
	if (*ptr && strcmp(ptr, "f")) return false;
	else if (v < 0) return false;
	_DB[date] = v;
	return true;
}

void BitcoinExchange::validData(std::string data) {
	size_t idx = data.find('|');
	std::string date = data.substr(0, idx);
	double cnt = atof((data.substr(idx + 1).c_str()));
	removeWhiteSpace(date);
	std::istringstream iss(date);
	std::ostringstream oss;
	std::string temp;

	size_t i = 3;
	while(i){
		std::getline(iss, temp, '-');
		switch (i)
		{
			case 3:
				oss << std::right << std::setfill('0') << std::setw(4) << temp;
				oss << '-';
				break;
			case 2:
				oss << std::right << std::setfill('0') << std::setw(2) << temp;
				oss << '-';
				break;
			case 1:
				oss << std::right << std::setfill('0') << std::setw(2) << temp;
				break;
		}
		i--;
	}
	date = oss.str();

	std::map<std::string, double>::iterator it = _DB.lower_bound(date);
	if (it->first == date) std::cout << date << " => " << trimTrailingZeros(cnt) << " = " << trimTrailingZeros(cnt * it->second) << "\n";
	else if (it == _DB.begin() && date != _DB.begin()->first) std::cerr << "Error: No coin information before " << date << "\n";
	else std::cout << date << " => " << trimTrailingZeros(cnt) << " = " << trimTrailingZeros(cnt * (--it)->second) << "\n";

}

void BitcoinExchange::execute(char* file){
	std::ifstream input(file);
	std::string read;
	int status = 0;
	int lineIdx = 2;

	if (!input) {
		std::cout << "Error: could not open " << file << " file.";
		throw std::runtime_error("");
	}else if (std::getline(input, read).eof()){
		std::cout << "Error: The " << file << " file is an empty file.";
		throw std::runtime_error("");
	}

	for (; !std::getline(input, read).eof() ;){
		if (read != "date | value." && !read.empty()){
			status = validInput(read);
			if (status == INVALID_ERROR){
				std::cout << "ERROR: bad input => " << lineIdx << " Line of " << file << " \"" << read << "\"\n";
			}
			else if (status == NOT_IN_SCOPE_VALUE_ERROR){
				std::cout << "ERROR: not in scope(0 < value < 1000) value => " << lineIdx << " Line of " << file << " \"" << read << "\"\n";
			}
			else validData(read);
		}
		lineIdx++;
	}
}

BitcoinExchange::BitcoinExchange(char* file, char* csvFile){
	std::ifstream csv(csvFile);
	std::string read;
	int lineIdx = 2;


	if (!csv)
		throw std::runtime_error("Error: could not open bitcoin DATA file.");
	else if (std::getline(csv, read).eof())
		throw std::runtime_error("Error: The bitcoin DATA file is an empty file.");

	for (; !std::getline(csv, read).eof();){
		if (read != "date,exchange_rate" && !read.empty()){
			if (!validDataCheck(read)){
				std::cout << lineIdx << " Line of " << file << "\n\"" << read << "\" ";
				throw std::runtime_error("Error: syntex error.");
			}
		}
		lineIdx++;
	}

	//_DB 데이터 확인
	// std::map<std::string, double>::iterator isBegin = _DB.begin();
	// for (; isBegin != _DB.end(); isBegin++){
	// 	std::cout << isBegin->first << "  " << isBegin->second << "\n";
	// }
	execute(file);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref){
	_DB = ref._DB;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref){
	if (this != &ref)
		_DB = ref._DB;
	return *this;
}
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){
}
