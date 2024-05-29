#include "AForm.hpp"

AForm::AForm() : _name("AForm") , _signed(false), _gradeTosign(1) , _gradeToexecute(1)  {}

AForm::AForm(const std::string& name, int gradetosign, int gradetoexecute) : _name(name) , _gradeTosign(gradetosign) , _gradeToexecute(gradetoexecute){
    if(gradetosign < 1 || gradetoexecute < 1)
        throw AForm::GradeTooHighException();
    if(gradetosign > 150 || gradetoexecute > 150)
        throw AForm::GradeTooLowException();
    this->_signed = false;
}


AForm::AForm(const AForm &other) : _name(other.getname()), _signed(other.getsigned()) \
 , _gradeTosign(other.getgradetosign()) , _gradeToexecute(other.getgradetoexecute()) 
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

AForm::~AForm() {
    std::cout  << "Base Destructor Called\n";
}

const std::string AForm::getname() const
{
    return (_name);
}

bool AForm::getsigned() const
{
    return (_signed);
}

int AForm::getgradetosign() const
{
    return (_gradeTosign);
}

int AForm::getgradetoexecute() const
{
    return (_gradeToexecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeTosign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}
const char *AForm::UnsignedFormexception::what() const throw()
{
    return "Unsigned AForm \n";
}

void AForm::execute(Bureaucrat const &executor) const{
    if (!this->_signed)
        throw AForm::UnsignedFormexception();
    if (executor.getGrade() > this->_gradeToexecute)
        throw AForm::GradeTooLowException();
    executed(executor);
}

std::ostream &operator<<(std::ostream &o, const AForm &ob)
{
    o << "AFORM INFO: " << std::endl;
    o << "AForm name: " << ob.getname() << std::endl
      << "Grade to sign: " << ob.getgradetosign() << std::endl
      << "Grade to execute: " << ob.getgradetoexecute() << std::endl
      <<  "Form : " << (ob.getsigned() ? "Signed" : "Not signed") << std::endl;
    return o;
}