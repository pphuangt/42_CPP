#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	static const int gradeToSign_ = 25;
	static const int gradeToExecute_ = 5;

	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

	~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const;

private:
	PresidentialPardonForm();
};

#endif
