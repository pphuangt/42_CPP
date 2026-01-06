#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int GradeToExecute, const std::string& target)
	: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(GradeToExecute), isSigned_(false), target_(target)
{
	if (gradeToSign < highestGrade_ || GradeToExecute < highestGrade_)
		throw AForm::GradeTooHighException();
	if (gradeToSign > lowestGrade_ || GradeToExecute > lowestGrade_)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name_(other.name_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_), isSigned_(other.isSigned_)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->isSigned_ = other.isSigned_;
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return name_;
}

int AForm::getGradeToSign() const
{
	return gradeToSign_;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute_;
}

bool AForm::getIsSigned() const
{
	return isSigned_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign_)
		throw AForm::GradeTooLowException();
	isSigned_ = true;
}

void AForm::execute(const Bureaucrat& bureaucrat)
{
	if (!isSigned_)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > gradeToExecute_)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "[Form]\n";
    os << "\tName: " << form.getName() << std::endl;
    os << "\tSigned status: " << form.getIsSigned() << std::endl;
    os << "\tSigned required grade: " << form.getGradeToSign() << std::endl;
    os << "\tExecuted required grade: " << form.getGradeToExecute() << std::endl;
	return os;
}
