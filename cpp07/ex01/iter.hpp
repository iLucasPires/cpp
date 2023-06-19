#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t lenght, void (*func)(T &))
{
  if (!array || !func)
    return;

  for (size_t i = 0; i < lenght; i++)
  {
    func(array[i]);
  }
}

template <typename T>
void iter(T const *array, size_t lenght, void (*func)(T const &))
{
  if (!array || !func)
    return;

  for (size_t i = 0; i < lenght; i++)
  {
    func(array[i]);
  }
}

#endif
