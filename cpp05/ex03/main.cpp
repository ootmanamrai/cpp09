#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{

    try
    {
        Bureaucrat bur("bure1", 1);
        Intern someRandomIntern;
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        bur.signForm(*rrf);
        bur.executeForm(*rrf);
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}