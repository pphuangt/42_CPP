#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
public:
	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	Form(const std::string& name, int gradeToSign, int GradetoExecute);
	Form(const Form& other);

	Form& operator=(const Form& other);

	~Form();

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

	Form();
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif
