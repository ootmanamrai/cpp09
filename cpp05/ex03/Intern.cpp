#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){
    if(this != &other)
        *this = other;
}

Intern &Intern::operator=(const Intern &other){
    (void)other;
    return(*this);
}


Intern::~Intern(){
    std::cout << "Intern Destructor Called\n";
}

AForm *Intern::makeForm(std::string Formname, std::string Targetname)
{
    std::string Fname[] = { "presidential pardon", "robotomy request", "shrubbery creation" };

    AForm *forms[] = {new PresidentialPardonForm(Targetname) , new RobotomyRequestForm(Targetname), new ShrubberyCreationForm(Targetname)};

    for(int i = 0; i < 3; i++)
    {
        if(Fname[i] == Formname)
        {
            std::cout << "Intern create " << Formname << std::endl;
            for(int j = i + 1; j < 3; j++)
                delete forms[j];
            return(forms[i]);
        }
        delete forms[i];
    }
    std::cout << "form not found\n";
    return NULL;
}