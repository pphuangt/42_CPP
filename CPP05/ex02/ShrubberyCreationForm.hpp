#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <string>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm: public AForm {
public:
	static const int gradeToSign_ = 145;
	static const int gradeToExecute_ = 137;

	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	void execute(const Bureaucrat& executor) const;

private:
	ShrubberyCreationForm();
};

#endif
