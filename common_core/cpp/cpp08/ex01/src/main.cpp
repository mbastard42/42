#include "Span.hpp"

int main(void) {

	std::vector<int> v(10, 4);
	Span _span(15);

	try {
		_span.addNumber(10);
		_span.addNumber(100);
		_span.addNumber(101);
		_span.addNumber(40);
		_span.addNumber(0);
		_span.addRange(v.begin(), v.end());
		// std::cout << _span << std::endl;
		std::cout << _span.shortestSpan() << std::endl;
		std::cout << _span.longestSpan() << std::endl;
	}
	catch (Span::TooMuchNbException & e) {std::cout << e.what() << std::endl;}
	catch (Span::NotEnoughtNbException & e) {std::cout << e.what() << std::endl;}
	return 0;
}
