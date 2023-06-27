#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

enum typeState
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSUEDOFLOAT,
	PSUEDODOUBLE,
	INVALID
};

struct dataType
{
	int integer;
	char character;
	float floating;
	double doubleing;
	char *input;
	size_t length;
	size_t position;
	typeState type;
};

class ScalarConverter
{
public:
	static void convert(std::string const &str);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &rhs);
};

#endif
