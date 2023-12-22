#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>

class RPN
{
public:
	RPN();
	RPN(std::string formula);
	RPN(const RPN& ref);
	RPN& operator=(const RPN& ref);
	~RPN();
};

#endif
