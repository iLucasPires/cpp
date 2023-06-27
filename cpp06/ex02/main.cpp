#include "Base.hpp"

Base *generate(void)
{
  int random = std::rand() % 3;

  switch (random)
  {
  case 0:
    return new A;
  case 1:
    return new B;
  default:
    return new C;
  }
}

void identify(Base *p)
{
  std::cout << "type: ";
  if (dynamic_cast<A *>(p))
    std::cout << 'A' << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << 'B' << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << 'C' << std::endl;
}

void identify(Base &p)
{
  std::cout << "type: ";

  try
  {
    dynamic_cast<A &>(p);
    std::cout << 'A' << std::endl;
  }
  catch (...)
  {
    try
    {
      dynamic_cast<B &>(p);
      std::cout << 'B' << std::endl;
    }
    catch (...)
    {
      try
      {
        dynamic_cast<C &>(p);
        std::cout << 'C' << std::endl;
      }
      catch (...)
      {
        std::cout << "Unknown" << std::endl;
      }
    }
  }
}

int main(void)
{
  std::srand(time(NULL));

  Base *base = generate();

  identify(*base);
  identify(base);
  return 0;
}
