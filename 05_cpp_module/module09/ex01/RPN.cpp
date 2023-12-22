#include "RPN.hpp"

bool isOperator(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/') return true;
	return false;
}

RPN::RPN(){}
RPN::RPN(std::string formula){
	std::stack<int> st;

	for (size_t i = 0; i < formula.length(); i++){
		if (formula[i] == ' ') continue;
		else if (std::isdigit(formula[i])) st.push(formula[i] - '0');
		else if (isOperator(formula[i])){
			if (st.size() < 2) throw std::runtime_error("Error: Formula that cannot be used");
			const int s = st.top();
			st.pop();
			const int f = st.top();
			st.pop();
			if (formula[i] == '+') st.push(f + s);
			else if (formula[i] == '-') st.push(f - s);
			else if (formula[i] == '*') st.push(f * s);
			else if (formula[i] == '/') st.push(f / s);
		} else {
			throw std::runtime_error("Error: Only numbers and (+, -, *, /) can be used as arguments.");
		}
	}

	if (st.size() != 1) throw std::runtime_error("Error: Formula that cannot be used");
	std::cout << st.top() << "\n";
}
RPN::RPN(const RPN& ref){
	*this = ref;
}
RPN& RPN::operator=(const RPN& ref){
	if (this != &ref){
	}
	return *this;
}
RPN::~RPN(){}
