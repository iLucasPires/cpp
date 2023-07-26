#include "RPN.hpp"

RPN::RPN()
{
}

void RPN::calc(char const *argv)
{
    std::string line = argv;
    float last = 0;
    float before_last = 0;
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
        {
            if (this->_stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return;
            }
            last = this->_stack.top();
            this->_stack.pop();
            before_last = this->_stack.top();
            this->_stack.pop();

            if (line[i] == '+')
                this->_stack.push(before_last + last);
            else if (line[i] == '-')
                this->_stack.push(before_last - last);
            else if (line[i] == '*')
                this->_stack.push(before_last * last);
            else if (line[i] == '/')
            {
                if (last == 0)
                {
                    std::cout << "Error" << std::endl;
                    return;
                }
                this->_stack.push(before_last / last);
            }
        }
        else
        {
            if (!isdigit(line[i]))
            {
                std::cout << "Error" << std::endl;
                return;
            }
            this->_stack.push(line[i] - '0');
        }
    }
    if (this->_stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    std::cout << this->_stack.top() << std::endl;
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
    if (this != &rhs)
    {
        this->_stack = rhs._stack;
    }
    return *this;
}
