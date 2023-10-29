#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(){
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	try
	{
		std::cout << *(easyfind(v, 5)) << " IDX =  " << easyfind(v,5) - v.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *(easyfind(d, 2)) << " IDX =  " << easyfind(v,2) - v.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *(easyfind(v, 100)) << " IDX =  " << easyfind(v,5) - v.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
