#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <fstream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
  public:
    BitcoinExchange(char const *argv);
    BitcoinExchange(BitcoinExchange const &src);
    ~BitcoinExchange();

    BitcoinExchange &operator=(BitcoinExchange const &rhs);

  private:
    std::string _aux[2];
    std::map<std::string, float> _exchange;
    std::map<std::string, float>::iterator _it;

    size_t _findIndex;
    std::ifstream _data;
    std::ifstream _input;
    std::string _line;

    void _getExchangeData();
    void _getInputData();
    float _stringToFloat(std::string &value);
    void _validateDateFormat(std::string &line);
};

#endif
