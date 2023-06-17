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

void ScalarConverter::convert(std::string const &str) {
  dataType data;

  data.t = verifyInput(str);
  data.p = str.find('.');

  if (data.p != std::string::npos) {
    data.p = str.length() - data.p - 1;
    if (data.t == FLOAT) data.p -= 1;
  }
   else {
    data.p = 1;
  }

  conversion(data, str);
  conversionPrint(data);
}

void ScalarConverter::conversion(dataType &data, std::string const &str) {
  if (data.t == CHAR) {
    data.c = static_cast<char>(str[0]);
    data.i = static_cast<int>(data.c);
    data.f = static_cast<float>(data.c);
    data.d = static_cast<double>(data.c);
  } else if (data.t == INT) {
    data.i = static_cast<int>(std::atol(str.c_str()));
    data.c = static_cast<char>(data.i);
    data.f = static_cast<float>(data.i);
    data.d = static_cast<double>(data.i);
  } else if (data.t == FLOAT) {
    data.f = static_cast<float>(std::atof(str.c_str()));
    data.i = static_cast<int>(data.f);
    data.d = static_cast<double>(data.f);
    data.c = static_cast<char>(data.f);
  } else if (data.t == DOUBLE) {
    data.d = static_cast<double>(std::strtod(str.c_str(), NULL));
    data.i = static_cast<int>(data.d);
    data.f = static_cast<float>(data.d);
    data.d = static_cast<double>(data.d);
  }
}

void ScalarConverter::conversionPrint(dataType &data) {
  std::cout << "char: ";
  if (IS_NON_DISPLAYABLE(data.c) && IS_ASCII(data.c)) {
    std::cout << "Non displayable\n";
  } else if (IS_CHAR(data.c)) {
    std::cout << "'" << data.c << "'\n";
  } else {
    std::cout << "impossible\n";
  }

  std::cout << "int: ";
  if (data.t != INVALID) {
    std::cout << data.i << '\n';
  } else {
    std::cout << "impossible\n";
  }

  std::cout << "float: ";
  if (data.f > std::numeric_limits<float>::max() ||
      data.f < std::numeric_limits<float>::min()) {
    std::cout << "impossible\n";
  } else if (data.t != INVALID) {
    std::cout << std::fixed << std::setprecision(data.p) << data.f << 'f'
              << '\n';
  }

  std::cout << "double: ";
  if (data.d > std::numeric_limits<double>::max() ||
      data.d < std::numeric_limits<double>::min()) {
    std::cout << "impossible\n";
  } else if (data.t != INVALID) {
    std::cout << std::fixed << std::setprecision(data.p) << data.d << '\n';
  }
}

typeState ScalarConverter::verifyInput(const std::string &str) {
  if (str == "-inff" || str == "+inff" || str == "nanf") return PSUEDOFLOAT;
  if (str == "-inf" || str == "+inf" || str == "nan") return PSUEDODOUBLE;

  int index = 0;
  int length = str.length();

  if (length == 1 && !IS_INT(str[0])) return CHAR;

  while (index < length) {
    if (IS_SIGN(str[index])) ++index;
    if (!IS_INT(str[index])) break;
    ++index;
  }
  if (index == length) return INT;

  if (str[index] == '.' && IS_INT(str[index + 1])) {
    ++index;

    while (index < length && IS_INT(str[index])) ++index;

    if ((str[index] == 'f' || str[index] == 'F') && index == length - 1)
      return FLOAT;
    if (index == length) return DOUBLE;
  }

  return INVALID;
}
