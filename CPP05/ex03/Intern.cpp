#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char* Intern::forms[] = {
	"shrubberycreation",
	"robotomyrequest",
	"presidentialpardon",
	NULL
};

AForm* (*Intern::makeFormFuncPtr[])(const char* target) = {
	&makeShrubberyCreationForm,
	&makeRobotomyRequestForm,
	&makePresidentialPardonForm
};

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	std::string normalized = normalizeFormName(name);

	for (size_t i = 0; forms[i] != NULL; i++) {
		if (normalized == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return makeFormFuncPtr[i](target.c_str());
		}
	}
	throw UnknowFormException();
}

AForm* Intern::makeShrubberyCreationForm(const char* target) { return new ShrubberyCreationForm(target); }

AForm* Intern::makeRobotomyRequestForm(const char* target) { return new RobotomyRequestForm(target); }

AForm* Intern::makePresidentialPardonForm(const char* target) { return new PresidentialPardonForm(target); }

std::string Intern::normalizeFormName(const std::string& name)
{
	std::string result;
	
	for (size_t i = 0; i < name.length(); i++)
	{
		char c = name[i];
		if (c == ' ')
			continue;
		result += std::tolower(c);
	}
	
	if (result.length() >= 4 && 
	    result.substr(result.length() - 4) == "form")
	{
		result = result.substr(0, result.length() - 4);
	}
	return result;
}

const char* Intern::UnknowFormException::what() const throw()
{
	return "Unknow form";
}
