#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    std::cout << "Assignment operator called" << std::endl;
    (void)rhs;
    return *this;
}

typeState verifyInput(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        return PSUEDOFLOAT;
    }
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        return PSUEDODOUBLE;
    }

    int length = str.length();

    if (length == 1 && !std::isdigit(str[0]))
    {
        return CHAR;
    }

    int index = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    while (index < length && std::isdigit(str[index]))
    {
        ++index;
    }

    if (index == length)
    {
        return INT;
    }

    if (str[index] == '.' && std::isdigit(str[index + 1]))
    {
        ++index;

        while (index < length && std::isdigit(str[index]))
            ++index;

        if ((str[index] == 'f' || str[index] == 'F') && index == length - 1)
            return FLOAT;
        if (index == length)
            return DOUBLE;
    }

    return INVALID;
}

void printDataType(const dataType &data)
{
    if (data.type == INVALID)
    {
        std::cout << "Char: impossible\nInt: impossible\nFloat: impossible\nDouble: impossible"
                  << std::endl;
        return;
    }

    std::cout << "Int: ";
    if (data.type != PSUEDOFLOAT && data.type != PSUEDODOUBLE)
    {
        if ((data.integer < std::numeric_limits<float>::min() ||
             data.integer > std::numeric_limits<float>::max()) &&
            (data.type == FLOAT || data.type == DOUBLE) && (data.integer > 0))
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            std::cout << data.integer << std::endl;
        }
    }
    else
    {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "Char: ";
    if (data.integer < 0 || data.integer > 127)
    {
        std::cout << "impossible" << std::endl;
    }
    else if (std::isprint(data.character))
    {
        std::cout << data.character << std::endl;
    }
    else
    {
        std::cout << "Non displayable" << std::endl;
    }

    std::cout << "Float: ";
    std::cout << std::fixed << std::setprecision(2) << data.floating << "f" << std::endl;

    std::cout << "Double: ";
    std::cout << std::fixed << std::setprecision(2) << data.doubleing << std::endl;
}

void convertData(dataType &data)
{
    std::stringstream ss(data.input);

    if (data.type == CHAR)
    {
        ss >> data.character;
        data.integer = static_cast<int>(data.character);
        data.floating = static_cast<float>(data.character);
        data.doubleing = static_cast<double>(data.character);
    }
    else if (data.type == INT)
    {
        ss >> data.integer;
        if (ss.fail())
        {
            data.type = INVALID;
        }
        else
        {
            data.character = static_cast<char>(data.integer);
            data.floating = static_cast<float>(data.integer);
            data.doubleing = static_cast<double>(data.integer);
        }
    }
    else if (data.type == FLOAT)
    {
        ss >> data.floating;
        if (ss.fail())
        {
            data.type = INVALID;
        }
        else
        {
            data.character = static_cast<char>(data.floating);
            data.integer = static_cast<int>(data.floating);
            data.doubleing = static_cast<double>(data.floating);
        }
    }
    else if (data.type == DOUBLE)
    {
        ss >> data.doubleing;
        if (ss.fail())
        {
            data.type = INVALID;
        }
        else
        {
            data.character = static_cast<char>(data.doubleing);
            data.integer = static_cast<int>(data.doubleing);
            data.floating = static_cast<float>(data.doubleing);
        }
    }
    else if (data.type == PSUEDOFLOAT || data.type == PSUEDODOUBLE)
    {
        data.floating = static_cast<float>(std::atof(data.input));
        data.character = static_cast<char>(data.floating);
        data.integer = static_cast<int>(data.floating);
        data.doubleing = static_cast<double>(data.floating);
    }
}

void ScalarConverter::convert(std::string const &str)
{
    dataType data;

    data.length = str.length();
    data.type = verifyInput(str);
    data.position = str.find('.');
    data.input = const_cast<char *>(str.c_str());

    convertData(data);
    printDataType(data);
}
