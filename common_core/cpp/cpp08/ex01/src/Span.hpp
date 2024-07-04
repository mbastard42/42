#pragma once

# include <set>
# include <vector>
# include <string>
# include <iostream>
# include <exception>

class Span {

	private :

	unsigned int _N;
	std::multiset<int> tab;

	protected :

	public :

	Span();
	Span(unsigned int);
	Span(const Span &);
	~Span();

	Span & operator=(const Span &);

	void addNumber(int);
	template<typename T>
		void addRange(T begin, T end) {

			for (T it = begin; it != end; it++) {
				if (tab.size() == _N)
					throw TooMuchNbException();
				tab.insert(*it);
			}
		}
	int shortestSpan() const;
	int longestSpan() const;
	unsigned int getN(void) const;
	std::multiset<int> getTab(void) const;
	class TooMuchNbException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Max elements number reached");}
	};
	class NotEnoughtNbException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Not enought elements to span");}
	};
};