#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
	public:
		// Constructor - Destructor - Copy
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		// Getter - Setter
		static void convert(const std::string &str);
};

#endif