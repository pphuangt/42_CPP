#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <exception>
# include "AForm.hpp"

class Intern {
public:
	class UnknowFormException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Intern();

	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target) const;

private:
	static const char* forms[];
	static AForm* (*makeFormFuncPtr[])(const char* target);

	Intern(const Intern& other);

	Intern& operator=(const Intern& other);

	static AForm* makeShrubberyCreationForm(const char* target);
	static AForm* makeRobotomyRequestForm(const char* target);
	static AForm* makePresidentialPardonForm(const char* target);
	static std::string normalizeFormName(const std::string& name);
};

#endif
