#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* form;
	Bureaucrat ceo("CEO", 1);

	std::cout << "Test intern makeForm() failure" << std::endl;
	try {
		form = intern.makeForm("home creation form", "Bob");
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	std::cout << "Test intern makeForm() success" << std::endl;
	try {
		form = intern.makeForm("shrubbery creation", "Home");
		std::cout << *form << std::endl;
		free(form);

		form = intern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		free(form);

		form = intern.makeForm("PresidentialPardon", "Cat");
		std::cout << *form << std::endl;
		free(form);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	std::cout << "Test with full operation success" << std::endl;
	try {
		form = intern.makeForm("robotomy request", "Bender");
		std::cout << *form;
		ceo.signForm(*form);
		std::cout << *form;
		ceo.executeForm(*form);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
