#include "PmergeMe.hpp"

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::printContainer(const std::string& str) {
	std::cout << str;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printTime(const std::string& ct, const double& time){
	std::cout << std::fixed << "Time to process a range of " << _vec.size() << " elements with std::" << ct << " : " << time << "s\n";
}

void PmergeMe::sort() {
	printContainer("Before:  ");
	clock_t start, end;
	//            ------------- vector ---------------
	start = clock();
	std::vector<std::pair<int,int> > vectorPairs = makePairsAndSort<std::vector<int>, std::vector<std::pair<int, int> > >(_vec);
	mergeSort(vectorPairs, 0, vectorPairs.size() - 1);
	insertion<std::vector<std::pair<int, int> >, std::vector<int> >(vectorPairs,_vec);
	end = clock();
	printContainer("After:   ");
	printTime("vector", static_cast<double>(end - start) / CLOCKS_PER_SEC);
	//            ------------- vector ---------------

	//            ------------- deque ---------------
	start = clock();
	std::deque<std::pair<int, int> > dequePairs = makePairsAndSort<std::deque<int>, std::deque<std::pair<int, int> > >(_deq);
	mergeSort(dequePairs, 0, dequePairs.size() - 1);
	insertion<std::deque<std::pair <int, int> >, std::deque<int> >(dequePairs, _deq);
	end = clock();
	printTime("deque", static_cast<double>(end - start) / CLOCKS_PER_SEC);
	//            ------------- deque ---------------
}

PmergeMe::PmergeMe() : _tempNum(-1) {}
PmergeMe::PmergeMe(int ac, char* av[]) : _tempNum(-1) {
	for (int i = 1; i < ac; i++){
		std::string num(av[i]);
		if (num.find_first_not_of("0123456789") != std::string::npos) {
			throw std::runtime_error("인자는 숫자, 양수만 가능합니다.");
		}
		long long n = std::atol(av[i]);
		if (n > INT_MAX) throw std::runtime_error("오버플로우");
		else if (n == 0) throw std::runtime_error("양수만 가능");
		_vec.push_back(static_cast<int>(n));
		_deq.push_back(static_cast<int>(n));
	}
}
PmergeMe::PmergeMe(const PmergeMe& ref){
	*this = ref;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& ref){
	if (this != &ref)	{
		_tempNum = ref._tempNum;
		_vec = ref._vec;
		_deq = ref._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe(){}
