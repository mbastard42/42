#pragma once

# include <string>
# include <iostream>

template <typename T>
void ft_swap(T & first, T & second) {

	T tmp;

	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T ft_min(T first, T second) {

	return first < second ? first : second;
}

template <typename T>
T ft_max(T first, T second) {

	return first > second ? first : second;
}
