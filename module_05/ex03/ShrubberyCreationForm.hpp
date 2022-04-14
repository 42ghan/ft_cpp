/**
 * @file ShrubberyCreationForm.hpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief A header file for ShrubberyCreationForm class
 * @date 2022-04-13
 */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "Form.hpp"
#include "color.hpp"

#define ASCII_TREE \
  "                                 @\n\
                              @ @ @  @ @ @\n\
                            @  @\\/@ @ /__@\n\
                            @@@ @\\ / @/  @ @\n\
                           @\\  \\/@| @ | @\n\
                          @__\\@ \\ |/ \\| / @\n\
                             __\\|@|  ||/__/@\n\
                            /  \\ \\  / /__\n\
                           @    \\  \\/ /   @\n\
                                 |\" '|\n\
                                 |\"  |\n\
                                 |\"  |\n\
                                ~|\"  |~\n\
                            ~~~~       ~~~~\n\
                          ~~               ~~~"

class Bureaucrat;
class Form;

class ShrubberyCreationForm : public Form {
 private:
  std::string target_;

 public:
  ShrubberyCreationForm(void);
  ~ShrubberyCreationForm(void);
  ShrubberyCreationForm(const std::string&);
  ShrubberyCreationForm(const ShrubberyCreationForm&);

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

  std::string getTarget(void) const;

  void execute(const Bureaucrat& executor) const;
};

#endif
