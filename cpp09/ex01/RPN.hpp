#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>

class RPN
{
  public:
    RPN();
    RPN(RPN const &src);
    ~RPN();

    RPN &operator=(RPN const &rhs);
    void calc(char const *argv);

  private:
    std::stack<float> _stack;
};

#endif
