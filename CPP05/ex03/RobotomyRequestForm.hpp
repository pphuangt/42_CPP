#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	static const int gradeToSign_ = 72;
	static const int gradeToExecute_ = 45;

	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const;

private:
	RobotomyRequestForm();
};

#endif
