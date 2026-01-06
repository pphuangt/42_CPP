#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name), grade_(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_), grade_(other.grade_)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade_ = other.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
	return name_;
}

int Bureaucrat::getGrade() const
{
	return grade_;
}

void Bureaucrat::promote()
{
	if (grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade_--;
}

void Bureaucrat::demote()
{
	if (grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade_++;
}

void Bureaucrat::signForm(AForm& form) const
{
	try {
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << name_ << " coundn't signed " << form.getName() << " because " << e.what() << "." << std::endl;
	}
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
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}
