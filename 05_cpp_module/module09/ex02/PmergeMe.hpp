#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <exception>
# include <utility>
# include <ctime>
# include <algorithm>
# include <climits>

class PmergeMe
{
private:
	std::deque<int> _deq;
	std::vector<int> _vec;
	int _tempNum;
public:
	void sort();
	void printContainer(const std::string& str);
	void printTime(const std::string& ct, const double& time);
	int jacobsthal(int n);

	template <typename T1, typename T2>
	T2 makePairsAndSort(T1& container){
		T2 pairs;

    	for (size_t i = 0; i < container.size(); i += 2) {
			if (i + 1 < container.size()) {
				if (container[i] > container[i + 1]) {
					pairs.push_back(std::make_pair(container[i], container[i + 1]));
				} else {
					pairs.push_back(std::make_pair(container[i + 1], container[i]));
				}
			} else {
				_tempNum = container[i];
		}
    }
	return pairs;
	}

	template <typename T>
	void mergeSort(T& pairs, int left, int right){
		if (left < right){
			int mid = (right + left) / 2;

			mergeSort(pairs, left, mid);
			mergeSort(pairs, mid + 1, right);
			merge(pairs, left, mid, right);
		}
	}

	template <typename T>
	void merge(T& pairs, int left, int mid, int rigth){
		int n1 = mid - left + 1;
		int n2 = rigth - mid;

		T L(n1), R(n2);

		for (int i = 0; i < n1; i++){
			L[i] = pairs[left + i];
		}
		for (int j = 0; j < n2; j++){
			R[j] = pairs[mid + j + 1];
		}

		int i = 0, j = 0;
		int k = left;

		while (i < n1 && j < n2){
			if (L[i].first <= R[j].first){
				pairs[k] = L[i];
				i++;
			}
			else {
				pairs[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			pairs[k] = L[i];
			i++;
			k++;
		}
		while (j < n2) {
			pairs[k] = R[j];
			j++;
			k++;
		}
	}

	template <typename T1, typename T2>
	void insertion(T1& pairs, T2& container){
		container.clear();
		for (size_t i = 0; i < pairs.size(); i++)
			container.push_back(pairs[i].first);
		typename T2::iterator it =  std::upper_bound(container.begin(), container.begin(), pairs[0].second);
		container.insert(it, pairs[0].second);
		//야콥스탈 3번째(3) 부터 시작
		int i = 3;
		int searchLimit = 1;
		int jacob;
		while ((jacob = jacobsthal(i)) <= static_cast<int>(pairs.size())){
			int rangeIncrement = 0;
			it =  std::upper_bound(container.begin(), container.begin() + ((jacob - 1) + searchLimit), pairs[jacob - 1].second);
			// std::cout << "jacob 탐색 범위 = "<< *(container.begin() + ((jacob - 1) + searchLimit)) << "\n";
			if (pairs[jacob - 1].second  <= pairs[jacob - 2].first)
				searchLimit++;
			else rangeIncrement++;
			container.insert(it, pairs[jacob - 1].second);
			for (int j = jacob - 1; j > jacobsthal(i - 1); j--){
				it =  std::upper_bound(container.begin(), container.begin() + ((j - 1) + searchLimit), pairs[j - 1].second);
				// std::cout << *(container.begin() + ((j - 1) + searchLimit)) << "\n";
				if (pairs[j - 1].second  <= pairs[j - 2].first)
					searchLimit++;
				else rangeIncrement++;
				container.insert(it, pairs[j - 1].second);
			}
			i++;
			searchLimit += rangeIncrement;
		}

		int rangeDecrease = 1;
		for (int j = pairs.size() - 1; j >= jacobsthal(i - 1); j--){
			searchLimit = container.size() - rangeDecrease;
			it =  std::upper_bound(container.begin(), container.begin() + searchLimit, pairs[j].second);
			// std::cout << "jacob for문 끝나고 탐색 범위 = "<< *(container.begin() + searchLimit) << "\n";
			if (pairs[j].second >= pairs[j - 1].first) rangeDecrease += 2;
			else rangeDecrease++;
			container.insert(it, pairs[j].second);
		}
		if (_tempNum != -1) {
			it =  std::upper_bound(container.begin(), container.end(), _tempNum);
			container.insert(it, _tempNum);
		}
	}

	PmergeMe();
	PmergeMe(int ac, char* av[]);
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator=(const PmergeMe& ref);
	~PmergeMe();
};

#endif

