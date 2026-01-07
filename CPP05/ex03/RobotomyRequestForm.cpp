#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", gradeToSign_, gradeToExecute_, target)
{
	static bool init = false;

	if (!init)
	{
		srand(time(NULL));
		init = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "drilling noises" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	}
	else {
		std::cout << getTarget() << "'s robotomy failed" << std::endl;
	}
}
