#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , _target("Default Target"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5) , _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) , _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void){
    std::cout  << " PresidentialPardonForm Destructor Called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if(this != &other)
    {
        _target = other._target;
        AForm::operator=(other);
    }
    return(*this);
}

void PresidentialPardonForm::executed(Bureaucrat const &executor) const
{
        (void)executor;
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
