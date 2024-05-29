#include "Form.hpp"
Form::Form(): _name("form"), _signed(false) , _gradeTosign(1)  , _gradeToexecute(1) {}

Form::Form(const std::string& name, int gradetosign) : _name(name) , _gradeTosign(gradetosign) , _gradeToexecute(1){
    if(gradetosign < 1 || _gradeToexecute < 1)
        throw Form::GradeTooHighException();
    if(gradetosign > 150 || _gradeToexecute > 150)
        throw Form::GradeTooLowException();
    this->_signed = false;
}

Form::Form(const Form &other) : _name(other.getname()), _signed(other.getsigned())\
 ,_gradeTosign(other.getgradetosign()) , _gradeToexecute(other.getgradetoexecute()){
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
        _signed = other._signed;
    return(*this);
}

Form::~Form()
{
    std::cout << _name << " Destructor Called \n";
}

const std::string Form::getname()const {
    return(_name);
}

bool Form::getsigned() const {
    return(_signed);
}

int Form::getgradetosign() const{
    return(_gradeTosign);
}

int Form::getgradetoexecute() const{
    return(_gradeToexecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeTosign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form : Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form : Grade too low";
}

std::ostream &operator<<(std::ostream &o, const Form &ob)
{
    o << "FORM INFO: " << std::endl;
    o << "Form name: " << ob.getname() << std::endl
      << "Grade to sign: " << ob.getgradetosign() << std::endl
      << "Grade to execute: " << ob.getgradetoexecute() << std::endl
      <<  "Form : " << (ob.getsigned() ? "Signed" : "Not signed") << std::endl;
    return o;
}