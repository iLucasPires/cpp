#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>

enum typeState { CHAR, INT, FLOAT, DOUBLE, PSUEDOFLOAT, PSUEDODOUBLE, INVALID };

struct dataType {
  int i;
  char c;
  float f;
  double d;
  size_t  p;
  typeState t;
};

#define IS_CHAR(c) ((c) >= 32 && (c) <= 126)
#define IS_INT(c) ((c) >= 48 && (c) <= 57)
#define IS_ASCII(c) ((c) >= 0 && (c) <= 127)
#define IS_NON_DISPLAYABLE(c) ((c) < 32 || (c) > 126)
#define IS_SIGN(c) ((c) == '-' || (c) == '+')

class ScalarConverter {
 public:
  static void convert(std::string const &str);

 private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter();
  ScalarConverter &operator=(ScalarConverter const &rhs);

  static typeState verifyInput(std::string const &str);
  static void conversion(dataType &data, std::string const &str);
  static void conversionPrint(dataType &data);
};

#endif
