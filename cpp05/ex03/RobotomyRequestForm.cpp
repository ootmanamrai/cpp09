#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm" , 72, 45) , _target("Default Target"){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm" , 72, 45) , _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) , _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
    {
        _target = other._target;
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    std::cout << "RobotomyRequestForm Destructor Called\n";
}

void RobotomyRequestForm::executed(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << "hahaha drilling noises ppppppp \n";
    static int i;
    if(i % 2 == 0)
    {
        std::cout << this->_target << " successfully robotomized!" << std::endl;
        i++;
    }
    else
    {
        std::cout <<  this->_target << " Robotomy failed !" << std::endl;
        i++;
    }
}