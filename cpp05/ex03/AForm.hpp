#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeTosign;
    const int _gradeToexecute;

public:
// Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradetosign, int gradetoexecute);
    AForm(const AForm &other);
    virtual ~AForm();
    AForm &operator=(const AForm &other);
// Getters Method
    const std::string getname() const;
    bool getsigned() const;
     int getgradetosign() const;
     int getgradetoexecute() const;
// Besigned & Execute Member Function
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;
    virtual void executed(Bureaucrat const &executor) const = 0;
// exception class
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class UnsignedFormexception : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const AForm &ob);
#endif