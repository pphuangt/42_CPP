#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int GradeToExecute)
	: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(GradeToExecute), isSigned_(false)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: name_(other.name_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_), isSigned_(other.isSigned_)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned_ = other.isSigned_;
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return name_;
}

int Form::getGradeToSign() const
{
	return gradeToSign_;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute_;
}

bool Form::getIsSigned() const
{
	return isSigned_;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign_ || bureaucrat.getGrade() > gradeToExecute_)
		throw Form::GradeTooLowException();
	isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "[Form]\n";
    os << "\tName: " << form.getName() << std::endl;
    os << "\tSigned status: " << form.getIsSigned() << std::endl;
    os << "\tSigned required grade: " << form.getGradeToSign() << std::endl;
    os << "\tExecuted required grade: " << form.getGradeToExecute() << std::endl;
	return os;
}
