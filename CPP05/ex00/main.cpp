#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("Name1", 150);
	Bureaucrat c("Name2", 1);

	std::cout << a;
	std::cout << b;
	std::cout << c;
}
