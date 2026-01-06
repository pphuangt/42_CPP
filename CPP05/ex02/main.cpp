#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm form("home");

	std::cout << boss;
	std::cout << form;
	std::cout << "Attemp to signed form" << std::endl;
	//boss.signedForm(form);
}
