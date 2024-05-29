#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern {
public :
//Orthodox Canonical Form 
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
// MakeForm Member Function  
    AForm *makeForm(std::string Formname, std::string Targetform);

};
#endif