# include "convert.hpp"

void toInt(std::string input) {

	int _int;
	size_t sz;
	bool good = false;

	try {
		_int = std::stoi(input, &sz);
		std::cout << "Int\t: " << _int << std::endl;
		good = true;
	} catch (std::out_of_range & e) {std::cout << "Int\t: " << "Overflow" << std::endl;}
	if (good) {
		if (isgraph(_int))
			std::cout << "Char\t: " << static_cast<char>(_int) << std::endl;
		else
			std::cout << "Char\t: undisplayable" << std::endl;
		std::cout << "Float\t: " << static_cast<float>(_int);
		if (input.length() <= 6 || (input.length() == 7 && _int < 0))
			std::cout << ".0";
		std::cout << "f\nDouble\t: " << static_cast<double>(_int);
		if (input.length() <= 6 || (input.length() == 7 && _int < 0))
			std::cout << ".0";
		std::cout << std::endl;
	} else {
		std::cout << "Char\t: can't cast from int" << std::endl;
		std::cout << "Float\t: can't cast from int" << std::endl;
		std::cout << "Double\t: can't cast from int" << std::endl;
	}
}

void toChar(std::string input) {

	std::cout << "Int\t: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "Char\t: " << input[0] << std::endl;
	std::cout << "Float\t: " << static_cast<float>(input[0]) << ".0f" << std::endl;
	std::cout << "Double\t: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

void toFloat(std::string input) {

	float _float;
	size_t sz;
	bool good = false;

	try {
		_float = std::stof(input, &sz);
		good = true;
	} catch (std::out_of_range & e) {}
	if (good) {
		if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff") {
			std::cout << "Int\t: impossible" << std::endl;
			std::cout << "Char\t: impossible" << std::endl;
		} else {
			std::cout << "Int\t: " << static_cast<int>(_float) << std::endl;
			if (isgraph(static_cast<int>(_float)))
				std::cout << "Char\t: " << static_cast<char>(_float) << std::endl;
			else
				std::cout << "Char\t: undisplayable" << std::endl;
		}
		for (size_t i = 0; i < input.length() - 1; i++)
			if (input[i] == '.')
				for (size_t j = i + 1; j < input.length() - 1; j++)
					if (input[j] != '0')
						good = false;
		std::cout << "Float\t: " << _float;
		if ((input.length() <= 7 && good && input != "nanf" && input != "inff" && input != "+inff" && input != "-inff") || (input.length() == 8 && _float < 0))
			std::cout << ".0";
		std::cout << "f\nDouble\t: " << static_cast<double>(_float);
		if ((input.length() <= 7 && good && input != "nanf" && input != "inff" && input != "+inff" && input != "-inff") || (input.length() == 8 && _float < 0))
			std::cout << ".0";
		std::cout << std::endl;
	} else {
		std::cout << "Int\t: can't cast from float" << std::endl;
		std::cout << "Char\t: can't cast from float" << std::endl;
		std::cout << "Float\t: Overflow" << std::endl;
		std::cout << "Double\t: can't cast from float" << std::endl;
	}
}

void toDouble(std::string input) {

	double _double;
	size_t sz;
	bool good = false;

	try {
		_double = std::stod(input, &sz);
		good = true;
	} catch (std::out_of_range & e) {}
	if (good) {
		if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf") {
			std::cout << "Int\t: impossible" << std::endl;
			std::cout << "Char\t: impossible" << std::endl;
		} else {
			std::cout << "Int\t: " << static_cast<int>(_double) << std::endl;
			if (isgraph(static_cast<int>(_double)))
				std::cout << "Char\t: " << static_cast<char>(_double) << std::endl;
			else
				std::cout << "Char\t: undisplayable" << std::endl;
		}
		for (size_t i = 0; i < input.length() - 1; i++)
			if (input[i] == '.')
				for (size_t j = i + 1; j < input.length() - 1; j++)
					if (input[j] != '0')
						good = false;
		std::cout << "Float\t: " << static_cast<float>(_double);
		if ((input.length() <= 6 && good && input != "nan" && input != "inf" && input != "+inf" && input != "-inf") || (input.length() == 8 && _double < 0))
			std::cout << ".0";
		std::cout << "f\nDouble\t: " << _double;
		if ((input.length() <= 6 && good && input != "nan" && input != "inf" && input != "+inf" && input != "-inf") || (input.length() == 8 && _double < 0))
			std::cout << ".0";
		std::cout << std::endl;
	} else {
		std::cout << "Int\t: can't cast from double" << std::endl;
		std::cout << "Char\t: can't cast from double" << std::endl;
		std::cout << "Float\t: can't cast from double" << std::endl;
		std::cout << "Double\t: Overflow" << std::endl;
	}
}
