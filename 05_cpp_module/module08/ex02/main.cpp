#include "MutantStack.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "------------ subject test ------------\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int> s(mstack);
		MutantStack<int>::iterator isBegin = s.begin();
		MutantStack<int>::iterator isEnd = s.end();
		while (isBegin != isEnd)
		{
			std::cout << *isBegin << std::endl;
			++isBegin;
		}
	}
	{
		std::cout << "------------ my test ------------\n";
		MutantStack<char> s;
		MutantStack<char> s2;
		for (int i = 'A'; i <= 'Z'; i++)
			s.push(i);
		std::cout << "s stack size :          " <<s.size() << "\n";
		s.pop();
		s.pop();
		std::cout << "pop * 2\n"<< "s stack size :          " << s.size() << "\n";
		MutantStack<char>::iterator isBegin = s.begin();
		MutantStack<char>::iterator isEnd = s.end();
		for (; isBegin != isEnd; isBegin++)
			std::cout << *isBegin << " ";
		std::cout << std::endl;
		std::cout << "s stack is empty??      " << (s.empty() ? "YES" : "NO") << "\n";
		std::cout << "s2 stack is empty??     " << (s2.empty() ? "YES" : "NO") << "\n";
	}
return 0;
}
