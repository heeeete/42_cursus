#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span
{
private:
	size_t	_size;
	std::vector<int> _v;
public:
	Span();
	Span(size_t size);
	Span(const Span& ref);
	Span& operator=(const Span& ref);
	~Span();

	void addNumber(int);
	void easyAdd(size_t);
	int shortestSpan() const;
	int longestSpan() const;

};



#endif
