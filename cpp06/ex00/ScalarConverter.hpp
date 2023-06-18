#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

enum typeState { CHAR, INT, FLOAT, DOUBLE, PSUEDOFLOAT, PSUEDODOUBLE, INVALID };

struct dataType {
  int integer;
  char character;
  float floating;
  double doubleing;
  char *input;
  bool valid[4] = {true, true, true, true};
  size_t length;
  size_t position;
  typeState type;
};

#define IS_CHAR(c) ((c) >= 32 && (c) <= 126)
#define IS_INT(c) ((c) >= 48 && (c) <= 57)
#define IS_ASCII(c) ((c) >= 0 && (c) <= 127)
#define IS_FLOAT(c) (c == 'f' || c == 'F')
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

    static void conversionChar(dataType &data);
    static void conversionInt(dataType &data);
    static void conversionFloat(dataType &data);
    static void conversionDouble(dataType &data);
};

#endif
