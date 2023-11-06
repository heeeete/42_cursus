#include "Array.hpp"

int main( void ) {
	{
		std::cout << "-------INT-------" << "\n";
		try
		{
			Array<int> arr(5);
			for (int i = 0; i < 5; i++)
				arr[i] = i;
			print(arr);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "-------CHAR-------" << "\n";
		try
		{
			Array<char> arr(5);
			for (int i = 0; i < 5; i++)
				arr[i] = 'A' + i;
			print(arr);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "-------COPY CONSTRUCTOR-------" << "\n";
		try
		{
			Array<char> arr(5);
			for (int i = 0; i < 5; i++)
				arr[i] = 'A' + i;
			Array<char> temp(arr);
			print(temp);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "-------ASSIGNMENT OPERATOR-------" << "\n";
		try
		{
			Array<char> arr(5);
			for (int i = 0; i < 5; i++)
				arr[i] = 'A' + i;
			Array<char> temp(5);
			for (int i = 0; i < 5; i++)
				temp[i] = 'a' + i;
			temp = arr;
			print(temp);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "-------EXCEPTION-------" << "\n";
		try
		{
		Array<char> arr(5);
			for (int i = 0; i < 6; i++)
				arr[i] = 'A' + i;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
