#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Form.hpp"
#include <iostream>
class Bureaucrat
{
private :
    const std::string name;
    int grade;
public :
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat  &other);
    Bureaucrat& operator=(const Bureaucrat  &other);
    ~Bureaucrat();
    std::string getName()const ;
    int getGrade()const ;
    void incremen();
    void decremen();
    void signForm(Form &form);
    void executeForm(Form const &form);
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