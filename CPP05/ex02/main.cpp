#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat ceo("CEO", Bureaucrat::highestGrade_);
	Bureaucrat intern("Intern", Bureaucrat::lowestGrade_);
	ShrubberyCreationForm s("Home");
	RobotomyRequestForm r("Office");
	PresidentialPardonForm p("Cat");

	std::cout << "Bureaucrat and Form infomation" << std::endl;
	std::cout << ceo;
	std::cout << intern;
	std::cout << s;
	std::cout << r;
	std::cout << p;
	std::cout << "--------------------" << std::endl;

	std::cout << "Test Bureaucrat executeForm() failure (form didn't signed)" << std::endl;
	ceo.executeForm(s);
	ceo.executeForm(r);
	ceo.executeForm(p);
	std::cout << "--------------------" << std::endl;

	std::cout << "Test Form execute() failure (form didn't signed)" << std::endl;
	try {
		s.execute(ceo);
		r.execute(ceo);
		p.execute(ceo);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	std::cout << "Signed form" << std::endl;
	ceo.signForm(s);
	ceo.signForm(r);
	ceo.signForm(p);
	std::cout << "--------------------" << std::endl;

	std::cout << "Test Bureaucrat executeForm() failure (grade to low to execute)" << std::endl;
	intern.executeForm(s);
	intern.executeForm(r);
	intern.executeForm(p);
	std::cout << "--------------------" << std::endl;

	std::cout << "Test Bureaucrat executeForm() success" << std::endl;
	ceo.executeForm(s);
	ceo.executeForm(r);
	ceo.executeForm(p);
	std::cout << "--------------------" << std::endl;

	std::cout << "Test Form execute() failure (grade to low to execute)" << std::endl;
	try {
		s.execute(intern);
		r.execute(intern);
		p.execute(intern);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	std::cout << "Test Form execute() success" << std::endl;
	try {
		s.execute(ceo);
		r.execute(ceo);
		p.execute(ceo);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}
