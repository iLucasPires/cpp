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
  (void)rhs;
  return *this;
}

typeState ScalarConverter::verifyInput(const std::string &str) {
  if (str == "-inff" || str == "+inff" || str == "nanf")
    return PSUEDOFLOAT;
  if (str == "-inf" || str == "+inf" || str == "nan")
    return PSUEDODOUBLE;

  int length = str.length();

  if (length == 1 && !IS_INT(str[0]) && IS_ASCII(str[0]))
    return CHAR;

  int index = (IS_SIGN(str[0])) ? 1 : 0;

  while (index < length && IS_INT(str[index])) {
    ++index;
  }

  if (index == length)
    return INT;

  if (str[index] == '.' && IS_INT(str[index + 1])) {
    ++index;

    while (index < length && IS_INT(str[index]))
      ++index;

    if ((str[index] == 'f' || str[index] == 'F') && index == length - 1)
      return FLOAT;
    if (index == length)
      return DOUBLE;
  }

  return INVALID;
}

void ScalarConverter::convert(std::string const &str) {
  dataType data;

  data.length = str.length();
  data.type = verifyInput(str);
  data.position = str.find('.');
  data.input = const_cast<char *>(str.c_str());
  data.position = (data.position == std::string::npos) ? 1 : data.length - data.position - 1;

  switch (data.type) {
    case CHAR: conversionChar(data); break;
    case INT: conversionInt(data); break;
    case FLOAT: conversionFloat(data); break;
    case DOUBLE: conversionDouble(data); break;
  }
}

void ScalarConverter::conversionChar(dataType &data) {
  data.character = static_cast<char>(data.input[0]);
  data.integer = static_cast<int>(data.character);
  data.floating = static_cast<float>(data.character);
  data.doubleing = static_cast<double>(data.character);
}

void ScalarConverter::conversionInt(dataType &data) {
  long int temp = std::atol(data.input);
  if (temp < std::numeric_limits<int>::min() ||
      temp > std::numeric_limits<int>::max())
      data.valid[INT] = false;

  data.integer = static_cast<int>(temp);

  data.character = static_cast<char>(data.integer);
  if (IS_NON_DISPLAYABLE(data.character))
    data.valid[CHAR] = false;

  data.floating = static_cast<float>(data.integer);
  data.doubleing = static_cast<double>(data.integer);
}

void ScalarConverter::conversionFloat(dataType &data) {
  data.floating = static_cast<float>(std::atof(data.input));
  data.integer = static_cast<int>(data.floating);
  data.doubleing = static_cast<double>(data.floating);
  data.character = static_cast<char>(data.floating);
}

void ScalarConverter::conversionDouble(dataType &data) {
  data.doubleing = static_cast<double>(std::strtod(data.input, NULL));
  data.integer = static_cast<int>(data.doubleing);
  data.floating = static_cast<float>(data.doubleing);
  data.character = static_cast<char>(data.doubleing);
}
