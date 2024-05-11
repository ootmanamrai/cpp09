#include "Form.hpp"
Form::Form(){}

Form::Form(const std::string& name, int gradetosign) : _name(name) , _gradeTosign(gradetosign) , _gradeToexecute(0){
    if(gradetosign < 1)
        throw Form::GradeTooHighException();
    if(gradetosign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other.getname()), _gradeTosign(other._gradeTosign()) , _gradeToexecute(other.getgradetoexecute()){
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
        _signed = other._signed;
    return(*this);
}

Form::~Form(){}

const std::string Form::getname(){
    return(_name);
}

bool Form::getsigned(){
    return(_signed);
}

const int Form::getgradetosign(){
    return(_gradeTosign);
}

const int Form::getgradetoexecute(){
    return(_gradeToexecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &o, const Form &ob)
{
    o << "FORM INFO: " << std::endl;
    o << "Form name: " << ob.getName() << std::endl
      << "Grade to sign: " << ob.getGradeToSign() << std::endl
      << "Grade to execute: " << ob.getGradeToExecute();
    return o;
}