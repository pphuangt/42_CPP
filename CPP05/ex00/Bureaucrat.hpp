#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	class GradeTooHighException: public std::exception
	{
		private:
			const std::string m_error;
		public:
			GradeTooHighException(const std::string& m_error);
			const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		private:
			const std::string m_error;
		public:
			GradeTooLowException(const std::string& m_error);
			const char* what() const throw();
	};

	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

#endif
