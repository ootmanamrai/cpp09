#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm  : public  AForm {
private :
     std::string _target;
public :
//Orthodox Canonical Form
     ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
//Member Function
    void executed(Bureaucrat const &executor) const;
};

#endif