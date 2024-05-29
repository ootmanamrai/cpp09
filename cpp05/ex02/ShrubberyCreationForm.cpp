#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , _target("Default Target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) , _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm Destructoro Called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
    {
        _target = other._target;
        AForm::operator=(other);
    }
    return(*this);
}

void ShrubberyCreationForm::executed(Bureaucrat const &executor) const{
    (void)executor;
    std::string name = this->_target + "_shrubbery";
    std::ofstream outfile(name.c_str());  
    if(outfile.is_open())
    {
        outfile << "         /\\\n";
        outfile << "        /  \\\n";
        outfile << "       /    \\\n";
        outfile << "      /      \\\n";
        outfile << "     /________\\\n";
        outfile << "       /\\  /\\\n";
        outfile << "      /  \\/  \\\n";
        outfile << "     /        \\\n";
        outfile << "    /__________\\\n";
        outfile << "        ||||\n";
        outfile << "        ||||\n";
        outfile.close();
    }
}