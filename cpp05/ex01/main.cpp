#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat b("rh", 8);
        Form form("Form1" , 9);
        b.signForm(form);
        std::cout << form;
        std::cout << "COPY" << std::endl;
        Form f1(form);
        std::cout << f1 << std::endl;
        std::cout << "OTHER TEST " << std::endl;
        Bureaucrat b1("OSMOS", 11);
        b1.signForm(f1);
    }
    catch (const std::exception &e)
    {
        std::cout << "catch exception:" << e.what() << std::endl;
    }
    
}
