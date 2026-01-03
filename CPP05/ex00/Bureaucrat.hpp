#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();

	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();
};
