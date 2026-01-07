#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", gradeToSign_, gradeToExecute_, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	const std::string filename = getTarget() + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs.is_open())
		throw std::runtime_error("Failed to create file: " + filename);

	ofs << "       _-_\n";
    ofs << "    /~~   ~~\\\n";
    ofs << " /~~         ~~\\\n";
    ofs << "{               }\n";
    ofs << " \\  _-     -_  /\n";
    ofs << "   ~  \\\\ //  ~\n";
    ofs << "_- -   | | _- _\n";
    ofs << "  _ -  | |   -_\n";
    ofs << "      // \\\\\n";
    
    ofs.close();
}
