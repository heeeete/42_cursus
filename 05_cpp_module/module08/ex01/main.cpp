# include "iostream"
# include <cstdlib>
# include <ctime>
# include "Span.hpp"

int main()
{
	srand(time(0));
	{
		std::cout << "------------ Subject Test ------------" << "\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		try
		{
			std::cout << "------------ OverSize Exception Test ------------" << "\n";
			Span sp(3);
			for (int i = 1; i <= 4; i++){
				sp.addNumber(i);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "------------ longestSpan Exception Test ------------" << "\n";
			Span sp(3);
			sp.addNumber(123123);
			std::cout << sp.longestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "------------ shortestSpan Exception Test ------------" << "\n";
			Span sp(3);
			sp.addNumber(123123);
			std::cout << sp.shortestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "------------ Big Value Test ------------" << "\n";
			Span sp(1000000);
			for (int i = 0; i < 1000000; i++)
				sp.addNumber(rand());
			Span sp2;
			sp2 = sp;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "------------ Big Value Test 2 ------------" << "\n";
			Span sp(10001);
			sp.easyAdd(10001);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
}
