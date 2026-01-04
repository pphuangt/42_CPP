#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name), grade(other.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::promote()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::demote()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low (maximum is 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
