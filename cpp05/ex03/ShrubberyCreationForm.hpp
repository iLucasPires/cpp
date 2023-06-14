#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

#define ASCII_TREE \
  "              * *\n\
           *    *  *\n\
      *  *    *     *  *\n\
     *     *    *  *    *\n\
 * *   *    *    *    *   *\n\
 *     *  *    * * .#  *   *\n\
 *   *     * #.  .# *   *\n\
  *     \"#.  #: #\" * *    *\n\
 *   * * \"#. ##\"       *\n\
   *       \"###\n\
             \"##\n\
              ##.\n\
              .##:\n\
              :###\n\
              ;###\n\
            ,####.\n\
/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\"\n"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

  std::string const getTarget() const;

  void execute(Bureaucrat const &executor) const;

 private:
  std::string const _target;
};

#endif
