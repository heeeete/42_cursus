#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <exception>
# include<utility>
# include <ctime>

class PmergeMe
{
private:
	std::deque<int> _deq;
	std::vector<int> _vec;
	int _tempNum;
public:
	void sort();
	std::vector<std::pair <int,int> > makePairsAndSortVector();
	std::deque<std::pair <int,int> > makePairsAndSortDeque();
	void printContainer(const std::string& str);
	void printTime(const std::string& ct, const double& time);
	void mergeInserionSortVector(std::vector<std::pair<int,int> >& vec, int left, int right);
	void mergeVector(std::vector<std::pair<int,int> >& vec, int left, int mid, int rigth);

	PmergeMe();
	PmergeMe(int ac, char* av[]);
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator=(const PmergeMe& ref);
	~PmergeMe();
};

#endif

