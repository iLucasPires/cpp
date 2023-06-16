#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
  std::cout << "Default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(ScalarConverter const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

ScalarConverter::~ScalarConverter() {
  std::cout << "Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  std::cout << "Assignment operator called" << std::endl;
  (void)rhs;  // to avoid unused parameter warning
  return *this;
}

void ScalarConverter::convert(std::string const str) {
  typeState type = verifyInput(str);
  dataType data;

  if (type == CHAR) {
    std::cout << "type: " << type << '\n';
    data.c = static_cast<char>(str[0]);
    data.i = static_cast<int>(data.c);
    data.f = static_cast<float>(data.c);
    data.d = static_cast<double>(data.c);
  } else if (type == INT) {
    data.i = static_cast<int>(std::atol(str.c_str()));
    data.c = static_cast<char>(data.i);
    data.f = static_cast<float>(data.i);
    data.d = static_cast<double>(data.i);
  } else if (type == FLOAT) {
    data.f = static_cast<float>(std::atof(str.c_str()));
    data.i = static_cast<int>(data.f);
    data.d = static_cast<double>(data.f);
    data.c = static_cast<char>(data.f);
  } else if (type == DOUBLE) {
    data.d = static_cast<double>(std::strtod(str.c_str(), NULL));
    data.i = static_cast<int>(data.d);
    data.f = static_cast<float>(data.d);
    data.d = static_cast<double>(data.d);
  }
  else if (type == INVALID)
  {
    std::cout << "Invalid input, please to use CHAR, INT, FLOAT or DOUBLE" << std::endl;
    return;
  }


  std::cout << "char: " << (IS_NON_DISPLAYABLE(data.c) ? "Non displayable" : std::string( 1, data.c));


  std::cout << std::endl;
}

typeState ScalarConverter::verifyInput(const std::string &str) {
  if (str == "-inff" || str == "+inff" || str == "nanf") return PSUEDOFLOAT;
  if (str == "-inf" || str == "+inf" || str == "nan") return PSUEDODOUBLE;

  int index = 0;
  int length = str.length();

  if (length == 1 && !IS_INT(str[0])) return CHAR;

  while (index < length) {
    while (IS_SIGN(str[index])) ++index;
    if (!IS_INT(str[index])) break;
    ++index;
  }
  if (index == length) return INT;

  if (str[index] == '.' && IS_INT(str[index + 1])) {
    ++index;

    while (index < length && IS_INT(str[index])) ++index;

    if (str[index] == 'f' && index == length - 1) return FLOAT;
    if (index == length) return DOUBLE;
  }

  return INVALID;
}
