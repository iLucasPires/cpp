#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->_findIndex = 0;
    std::ifstream data("data.csv");
    std::ifstream input("input.csv");
    if (data.fail() || input.fail())
    {
        std::cout << "Error: could not open file data.csv or input.csv" << std::endl;
        return;
    }
    this->_getExchangeData(data);
    this->_getInputData(input);

    data.close();
    input.close();
}

BitcoinExchange::BitcoinExchange(char const *argv)
{
    this->_findIndex = 0;
    std::ifstream data("data.csv");
    std::ifstream input(argv);
    if (data.fail() || input.fail())
    {
        std::cout << "Error: could not open file " << argv << " or data.csv" << std::endl;
        return;
    }
    this->_getExchangeData(data);
    this->_getInputData(input);

    data.close();
    input.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        this->_findIndex = rhs._findIndex;
        this->_aux[0] = rhs._aux[0];
        this->_aux[1] = rhs._aux[1];
        this->_exchange = rhs._exchange;
        this->_it = rhs._it;
    }
    return *this;
}

void BitcoinExchange::_getExchangeData(std::ifstream &data)
{
    std::string line;

    while (std::getline(data, line))
    {
        if (line.empty() == false)
        {
            this->_findIndex = line.find(",");
            this->_aux[0] = line.substr(0, this->_findIndex);
            this->_aux[1] = line.substr(this->_findIndex + 1);
            this->_exchange.insert(std::pair<std::string, float>(this->_aux[0], std::atof(this->_aux[1].c_str())));
        }
    }
}

void BitcoinExchange::_getInputData(std::ifstream &input)
{
    std::string line;
    while (std::getline(input, line))
    {
        if (line.empty() == false)
        {
            this->_findIndex = line.find("|");
            if (this->_findIndex == std::string::npos)
            {
                std::cout << "Error: bad input => " << line << std::endl;
            }
            else
            {
                this->_aux[0] = line.substr(0, this->_findIndex);
                this->_aux[1] = line.substr(this->_findIndex + 1);

                this->_aux[0].erase(std::remove(this->_aux[0].begin(), this->_aux[0].end(), ' '), this->_aux[0].end());
                this->_aux[1].erase(std::remove(this->_aux[1].begin(), this->_aux[1].end(), ' '), this->_aux[1].end());
                try
                {
                    this->_validateDateFormat(this->_aux[0]);
                    this->_it = this->_exchange.upper_bound(this->_aux[0]);
                    if (this->_it != this->_exchange.begin())
                    {
                        this->_it--;
                    }
                    float value = this->_stringToFloat(this->_aux[1]) * this->_it->second;
                    std::cout << this->_aux[0] << " " << this->_aux[1] << " = " << value << " BTC" << std::endl;
                }
                catch (std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
        }
    }
}

float BitcoinExchange::_stringToFloat(std::string &value)
{
    std::stringstream ss(value);
    double value_double = 0;

    ss >> value_double;
    if (ss.fail() || !ss.eof())
    {
        throw std::runtime_error("Error: could not convert " + value);
    }
    if (value_double > 1000)
    {
        throw std::runtime_error("Error: too large a number");
    }
    if (value_double < 0)
    {
        throw std::runtime_error("Error: not a positive number");
    }

    return value_double;
}

void BitcoinExchange::_validateDateFormat(std::string &line)
{
    if (line.length() != 10 || line[4] != '-' || line[7] != '-')
    {
        throw std::runtime_error("Error: bad input => " + line);
    }

    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    if (year < 2000 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        throw std::runtime_error("Error: bad input => " + line);
    }
}
