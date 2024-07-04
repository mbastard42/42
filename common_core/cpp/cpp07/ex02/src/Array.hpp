#pragma once

# include <string>
# include <iostream>

template <typename T>
class Array {

	private :

	T * _tab;
	size_t _size;

	public :

	Array() : _tab(NULL), _size(0) {}
	Array(unsigned int n) : _tab(new T[n]), _size(n) {}
	Array(const Array & src) : _tab(new T[src._size]), _size(src._size) {

		for (size_t i = 0; i < _size; i++)
			_tab[i] = src._tab[i];
	}
	~Array() {delete [] _tab;}

	Array & operator=(const Array & src) {

		delete [] _tab;
		_size = src._size;
		_tab = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_tab[i] = src._tab[i];
		return *this;
	}
	T &	operator[](size_t n) {

		if (n >= _size)
			throw std::exception();
		return _tab[n];
	}
	T * tab() const {return _tab;}
	size_t size() const {return _size;}
};

template <typename T>
std::ostream &	operator<<(std::ostream & o, Array<T> const & a) {

	for (size_t i = 0; i < a.size(); i++)
		o << a.tab()[i] << std::endl;
	return o;
}

