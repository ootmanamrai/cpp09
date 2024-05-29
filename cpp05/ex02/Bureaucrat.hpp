#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "AForm.hpp"
#include <iostream>

class Bureaucrat
{
private :
    const std::string name;
    int grade;
public :
// Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat  &other);
    Bureaucrat& operator=(const Bureaucrat  &other);
    ~Bureaucrat();
// Getters Method
    std::string getName()const ;
    int getGrade()const ;
// Increment & Decrement member functions
    void incremen();
    void decremen();
// Sing & Execute Form member functions
    void signForm(AForm &Aform);
    void executeForm(AForm const &form);
// Exception class
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &ob);
#endif