
#include "ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	std::cout << "Copy ScalarConverter constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "Destructor ScalarConverter called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src) {
	(void)src;
	std::cout << "Copy ScalarConverter assignment operator called" << std::endl;
	return *this;
}

void	printChar(char c) {
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void	printFloat(float f) {
	std::cout << "float: " << f << ".0f" << std::endl;
}

void	printDouble(double d) {
	std::cout << "double: " << d << ".0" << std::endl;
}

char	toChar(const std::string& str) {
	char c;

	c = str[0];
	return c;
}

float	toFloat(std::string str) {
	// Permet de manipuler des chaînes de caractères comme si elles étaient
	// des flux d'entrée ou de sortie.
	std::stringstream ss;
	float f;

	// Remove the 'f' at the end of the string with pop_back()
	str.pop_back();

	// Put the string into the stream
	ss << str;

	// Extract the float from the stream
	ss >> f;

	// Clear the stream
	ss.clear();

	return f;
}

double toDouble(const std::string& str) {
	std::stringstream ss;
	double d;

	ss << str;
	ss >> d;
	ss.clear();
	return d;
}

int toInt(const std::string& str) {
	std::stringstream ss;
	int i;

	ss << str;
	ss >> i;
	ss.clear();
	return i;
}

void	ScalarConverter::convert(const std::string& str) {

	// 1. Check if the string is a char
	if (str.length() == 1 && !isdigit(str[0])) {
		char c = toChar(str);
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
	}
	// 2. Check if the string is a float or -inff, +inff or nanf
	else if (str.back() == 'f') {
		float f = toFloat(str);
		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
	// 3. Check if the string is a double
	else if (str.find('.') != std::string::npos) {
		double d = toDouble(str);
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
	}
	// 4. Check if the string is an int
	else {
		int i = toInt(str);
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
	}
}