#include "Span.hpp"

Span::Span(void) : _N(0) {

	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {

	std::cout << "Span nb constructor called" << std::endl;
}

Span::Span(const Span & src) : _N(src.getN()) {

	std::cout << "Span copy constructor called" << std::endl;
	tab.clear();
	tab.insert(src.tab.begin(), src.tab.end());
}

Span::~Span(void) {

	std::cout << "Span deconstructor called" << std::endl;
}

void Span::addNumber(int nb) {

	if (tab.size() < _N) {
		tab.insert(nb);
	} else
		throw TooMuchNbException();
}

int Span::longestSpan(void) const {

	if (tab.size() < 2)
		throw NotEnoughtNbException();
	return *tab.rbegin() - *tab.begin();
}

int Span::shortestSpan(void) const {

	int _span = *tab.rbegin() - *tab.begin();

	if (tab.size() < 2)
		throw NotEnoughtNbException();
	for (std::multiset<int>::const_iterator it = tab.begin(); std::next(it, 1) != tab.end(); it++) {
		if (*std::next(it, 1) - *it < _span) {
			_span = *std::next(it, 1) - *it;
		}
	}
	return _span;
}

unsigned int Span::getN(void) const {
	
	return _N;
}

std::multiset<int> Span::getTab(void) const {
	
	return tab;
}

Span & Span::operator=(Span const & src __unused) {

	std::cout << "Copy assignment operator called" << std::endl;
	_N = src._N;
	tab.clear();
	tab.insert(src.tab.begin(), src.tab.end());
	return *this;
}
