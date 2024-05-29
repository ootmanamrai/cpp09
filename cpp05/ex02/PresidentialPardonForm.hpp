#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private :
    std::string _target;

public :
// Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
// Executed Member Function
    void executed(Bureaucrat const &executor) const;
};
#endif