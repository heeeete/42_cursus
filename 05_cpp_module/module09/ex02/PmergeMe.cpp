#include "PmergeMe.hpp"

int jacobsthal(int n) {
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

std::deque<std::pair <int,int> > PmergeMe::makePairsAndSortDeque() {
	std::deque<std::pair<int,int> > pairs;

    for (size_t i = 0; i < _deq.size(); i += 2) {
        if (i + 1 < _deq.size()) {
            if (_deq[i] > _deq[i + 1]) {
                pairs.push_back(std::make_pair(_deq[i + 1], _deq[i]));
            } else {
                pairs.push_back(std::make_pair(_deq[i], _deq[i + 1]));
            }
        } else {
			_tempNum = _deq[i];
        }
    }
    std::sort(pairs.begin(), pairs.end());

	return pairs;
}

std::vector<std::pair<int,int> > PmergeMe::makePairsAndSortVector() {
	std::vector<std::pair<int,int> > pairs;

    for (size_t i = 0; i < _vec.size(); i += 2) {
        if (i + 1 < _vec.size()) {
            if (_vec[i] > _vec[i + 1]) {
                pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
            } else {
                pairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
            }
        } else {
			_tempNum = _vec[i];
        }
    }

	return pairs;
}

void PmergeMe::mergeVector(std::vector<std::pair<int,int> >& vec, int left, int mid, int rigth){
	int n1 = mid - left + 1;
	int n2 = rigth - mid;

	std::vector<std::pair<int, int> > L(n1), R(n2);

	for (int i = 0; i < n1; i++){
		L[i] = vec[left + i];
	}
	for (int j = 0; j < n2; j++){
		R[j] = vec[mid + j + 1];
	}

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2){
		if (L[i].first <= R[j].first){
			vec[k] = L[i];
			i++;
		}
		else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSortVector(std::vector<std::pair<int,int> >& vec, int left, int right){
	if (left < right){
		int mid = (right + left) / 2;

		mergeSortVector(vec, left, mid);
		mergeSortVector(vec, mid + 1, right);
		mergeVector(vec, left, mid, right);
	}
}

void PmergeMe::insertionVector(std::vector<std::pair<int,int> >& pairs){
	_vec.clear();
	for (size_t i = 0; i < pairs.size(); i++)
		_vec.push_back(pairs[i].first);	//정렬된 큰 수를 _vec에 다 담음
	std::vector<int>::iterator it =  std::upper_bound(_vec.begin(), _vec.end(), pairs[0].second);
	_vec.insert(it, pairs[0].second);
	int i = 3;
	int jacob;
	while ((jacob = jacobsthal(i)) <= static_cast<int>(pairs.size())){
		std::vector<int>::iterator it =  std::upper_bound(_vec.begin(), _vec.end(), pairs[jacob - 1].second);
		_vec.insert(it, pairs[jacob - 1].second);
		for (int j = jacob - 1; j > jacobsthal(i - 1); j--){
			std::vector<int>::iterator it =  std::upper_bound(_vec.begin(), _vec.end(), pairs[j - 1].second);
			_vec.insert(it, pairs[j - 1].second);
		}
		i++;
	}
	for (int j = pairs.size() - 1; j >= jacobsthal(i - 1); j--){
		std::vector<int>::iterator it =  std::upper_bound(_vec.begin(), _vec.end(), pairs[j].second);
		_vec.insert(it, pairs[j].second);
	}
	if (_tempNum != -1) {
		std::vector<int>::iterator it =  std::upper_bound(_vec.begin(), _vec.end(), _tempNum);
		_vec.insert(it, _tempNum);
	}
}


void PmergeMe::sort() {
	printContainer("Before:  ");
	int a = _vec.size();
	clock_t start, end;
	//            ------------- vector ---------------
	start = clock();
	std::vector<std::pair<int,int> > pairs = makePairsAndSortVector();
	mergeSortVector(pairs, 0, pairs.size() - 1);
	insertionVector(pairs);
	end = clock();
	printContainer("After:   ");
	printTime("vector", static_cast<double>(end - start) / CLOCKS_PER_SEC);
	int b = _vec.size();
	std::cout << a<< " " << b<<"\n";
	std::vector<int> qq = _vec;
	std::sort(qq.begin(), qq.end());
	for (size_t i = 0; i < qq.size(); i++){
		if (_vec[i] != qq[i]) std::cout << "다름\n";
	}
	std::cout << "같음\n";




	//            ------------- vector ---------------

	// //            ------------- deque ---------------
	// start = clock();
	// std::deque<std::pair<int,int> > deqPair = makePairsAndSortDeque();

	// _deq.clear();
	// for (size_t i = 0; i < deqPair.size(); i++)
	// 	_deq.push_back(deqPair[i].first);	//정렬된 큰 수를 _vec에 다 담음

	// for (size_t i = 0; i < deqPair.size(); i++){
	// 	//upper_bound 함수는 Binary search로 비교 횟수를 최적화
	// 	std::deque<int>::iterator it =  std::upper_bound(_deq.begin(), _deq.end(), deqPair[i].second);
	// 	_deq.insert(it, deqPair[i].second);
	// }
	// if (_tempNum != -1) {
	// 	std::deque<int>::iterator it =  std::upper_bound(_deq.begin(), _deq.end(), _tempNum);
	// 	_deq.insert(it, _tempNum);
	// }
	// end = clock();
	// printTime("deque", static_cast<double>(end - start) / CLOCKS_PER_SEC);
	// //            ------------- deque ---------------
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
