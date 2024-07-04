# include "convert.hpp"

ptr getType(std::string input) {

	int pt = 0;
	ptr type = &toInt;

	if (!input.length())
		type = NULL;
	else if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
		type = &toChar;
	else if (input == "nanf" || input == "-inff" || input == "inff" || input == "+inff")
		type = &toFloat;
	else if (input == "nan" || input == "-inf" || input == "inf" || input == "+inf")
		type = &toDouble;
	else { for (size_t i = 0; type && i < input.length(); i++) {
		if (!i && input[i] == '-')
			i++;
		if (input[i] == '.' && ++pt)
			type = &toDouble;
		if (input[i] == 'f' && i == input.length() - 1)
			type = &toFloat;
		if (pt > 1 || (isascii(input[i]) && !isdigit(input[i]) && type != &toFloat && input[i] != '.'))
			type = NULL;
	}}
	return type;
}

int main(int ac, char **av) {

	ptr convert = NULL;

	if (ac == 2 && av[1])
		convert = getType(av[1]);
	if (convert)
		convert(av[1]);
	else
		std::cout << "Invalid input" << std::endl;
	return 0;
}
