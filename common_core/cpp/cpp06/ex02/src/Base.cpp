# include "Base.hpp"

Base::~Base(void) {

	std::cout << "Base deconstructor called" << std::endl;
}

Base * generate(void) {

	int rd = static_cast<int>(time(NULL)) % 3;
	Base *list[3] = {new A, new B, new C};

	for (int i = 0; i < 3; i++)
		if (i != rd)
			delete list[i];
	return list[rd];
}

void identify(Base * _base) {

	Base * tmp;

	tmp = dynamic_cast<A *>(_base);
	if (!tmp) {
		tmp = dynamic_cast<B *>(_base);
		if (!tmp) {
			tmp = dynamic_cast<C *>(_base);
			if (!tmp)
				std::cout << "Class type is Base" << std::endl;
			else {std::cout << "Class type is C" << std::endl;}
		} else {std::cout << "Class type is B" << std::endl;}
	} else {std::cout << "Class type is A" << std::endl;}
}

void identify(Base & _base) {

	try {
		A & _a = dynamic_cast<A &>(_base);
		(void)_a;
		std::cout << "Class type is A" << std::endl;
	} catch (std::bad_cast & e) {
		try {
			B & _b = dynamic_cast<B &>(_base);
			(void)_b;
			std::cout << "Class type is B" << std::endl;
		} catch (std::bad_cast & e) {
			try {
				C & _c = dynamic_cast<C &>(_base);
				(void)_c;
				std::cout << "Class type is C" << std::endl;
			} catch (std::bad_cast & e) {std::cout << "Class type is Base" << std::endl;}
		}
	}
}
