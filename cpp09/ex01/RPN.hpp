#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
  public:
    RPN(char const *argv);
    RPN(RPN const &src);
    ~RPN();

    RPN &operator=(RPN const &rhs);

  private:
    std::stack<float> _stack;

    void _getLastTwoValuesFromStack(float lastValues[2]);
};

#endif
