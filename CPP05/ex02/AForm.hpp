#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
public:
	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	AForm(const std::string& name, int gradeToSign, int GradetoExecute);
	AForm(const AForm& other);

	AForm& operator=(const AForm& other);

	~AForm();

	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);

private:
	const std::string name_;
	const int gradeToSign_;
	const int gradeToExecute_;
	bool isSigned_;

	AForm();
};

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif
