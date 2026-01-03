#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	:name(name), grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(orther.name), grade(orther.grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		name = other.name;
		grade = other.grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}
