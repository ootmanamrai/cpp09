#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bur") , grade(1){}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade) : name(Name) , grade(Grade)
{
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat  &other) : name(other.name) , grade(other.grade){
    std::cout << name << "Copy Constructor Called ";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->grade = other.getGrade();
    return(*this);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

std::string Bureaucrat::getName() const{
    return(this->name);
}


void Bureaucrat::increment()
{
    if(grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement()
{
    if(grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destrutor called " << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
        return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &ob)
{
    o << ob.getName() << ", bureaucrat grade " << ob.getGrade() << std::endl;
    return o;
}