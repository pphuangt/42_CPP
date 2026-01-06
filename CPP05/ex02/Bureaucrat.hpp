#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat {
public:
	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	static const int highestGrade_ = 1;
	static const int lowestGrade_ = 150;

	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);

	Bureaucrat& operator=(const Bureaucrat& other);

	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void promote();
	void demote();
	void signForm(AForm& form) const;
	void executeForm(const AForm& form) const;

private:
	const std::string name_;
	int grade_;

	Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
