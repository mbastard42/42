#pragma once

# include <string>
# include <vector>
# include <iterator>
# include <iostream>

template <typename T>
bool easyfind(const T & container, int _int) {

	return find(container.begin(), container.end(), _int) != container.end() ? true : false;
}
