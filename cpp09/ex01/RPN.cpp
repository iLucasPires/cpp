#include "RPN.hpp"

RPN::RPN(const char *argv)
{
    std::string line;
    std::istringstream iss(argv);

    float value;
    float lastValues[2];
    while (std::getline(iss, line, ' '))
    {
        if (line == "+" || line == "-" || line == "*" || line == "/")
        {
            this->_getLastTwoValuesFromStack(lastValues);

            if (line == "+")
                _stack.push(lastValues[1] + lastValues[0]);
            else if (line == "-")
                _stack.push(lastValues[1] - lastValues[0]);
            else if (line == "*")
                _stack.push(lastValues[1] * lastValues[0]);
            else if (line == "/")
            {
                if (lastValues[0] == 0)
                {
                    std::cout << "Error: division by zero" << std::endl;
                    return;
                }
                _stack.push(lastValues[1] / lastValues[0]);
            }
        }
        else
        {
            bool validNumber = true;
            for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
            {
                if (!isdigit(*it) && *it != '.' && *it != '-')
                {
                    validNumber = false;
                    break;
                }
            }

            if (validNumber)
            {
                try
                {
                    value = atof(line.c_str());
                    if (value >10 || value < 0)
                    {
                        std::cout << "Error: invalid value" << std::endl;
                        return;
                    }

                    _stack.push(value);
                }
                catch (const std::exception &e)
                {
                    std::cout << "Error: invalid value" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Error: invalid expression" << std::endl;
                return;
            }
        }
    }
    if (_stack.size() != 1)
    {
        std::cout << "Error: invalid expression" << std::endl;
        return;
    }
    std::cout << _stack.top() << std::endl;
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &rhs)
{
    (void)rhs;
    // if (this != &rhs)
    // {
    // }
    return *this;
}

void RPN::_getLastTwoValuesFromStack(float lastValues[2])
{
    if (this->_stack.size() < 2)
    {
        std::cout << "Error: not enough values" << std::endl;
        exit(1);
    }
    lastValues[0] = this->_stack.top();
    this->_stack.pop();
    lastValues[1] = this->_stack.top();
    this->_stack.pop();
}
