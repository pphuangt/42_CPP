#include "Bureaucrat.hpp"

void test_valid_creation();
void test_invalid_grade_high();
void test_invalid_grade_low();
void test_promote();
void test_promote_boundary();
void test_demote();
void test_demote_boundary();
void test_copy_constructor();
void test_assignment_operator();

int main()
{
	std::cout << "Running Bureaucrat Tests\n" << std::endl;

	test_valid_creation();
	test_invalid_grade_high();
	test_invalid_grade_low();
	test_promote();
	test_promote_boundary();
	test_demote();
	test_demote_boundary();
	test_copy_constructor();
	test_assignment_operator();

	std::cout << "\nAll tests completed!" << std::endl;
	return 0;
}

void test_valid_creation()
{
    std::cout << "Test: Valid creation" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        Bureaucrat b3("Charlie", 75);
        std::cout << "  " << b1 << std::endl;
        std::cout << "  " << b2 << std::endl;
        std::cout << "  " << b3 << std::endl;
        std::cout << "  ✓ Pass\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: " << e.what() << "\n" << std::endl;
    }
}

void test_invalid_grade_low()
{
    std::cout << "Test: Invalid grade too low (151)" << std::endl;
    try {
        Bureaucrat b("Invalid", 151);
        std::cerr << "  ✗ Fail: Should have thrown exception\n" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "  Caught: " << e.what() << std::endl;
        std::cout << "  ✓ Pass\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: Wrong exception: " << e.what() << "\n" << std::endl;
    }
}

void test_invalid_grade_high()
{
    std::cout << "Test: Invalid grade too high (0 and -1)" << std::endl;
    try {
        Bureaucrat b1("Invalid1", 0);
        std::cerr << "  ✗ Fail: Grade 0 should have thrown exception" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "  Caught (grade 0): " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b2("Invalid2", -1);
        std::cerr << "  ✗ Fail: Grade -1 should have thrown exception" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "  Caught (grade -1): " << e.what() << std::endl;
        std::cout << "  ✓ Pass\n" << std::endl;
    }
}

void test_promote()
{
    std::cout << "Test: Promote (valid)" << std::endl;
    try {
        Bureaucrat b("Promotable", 5);
        std::cout << "  Before: " << b << std::endl;
        b.promote();
        std::cout << "  After:  " << b << std::endl;
        
        if (b.getGrade() == 4) {
            std::cout << "  ✓ Pass\n" << std::endl;
        } else {
            std::cerr << "  ✗ Fail: Grade should be 4\n" << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: " << e.what() << "\n" << std::endl;
    }
}

void test_promote_boundary()
{
    std::cout << "Test: Promote at boundary (grade 1)" << std::endl;
    try {
        Bureaucrat b("TopBureaucrat", 1);
        std::cout << "  Before: " << b << std::endl;
        b.promote();
        std::cerr << "  ✗ Fail: Should have thrown exception\n" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "  Caught: " << e.what() << std::endl;
        std::cout << "  ✓ Pass\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: Wrong exception: " << e.what() << "\n" << std::endl;
    }
}

void test_demote()
{
    std::cout << "Test: Demote (valid)" << std::endl;
    try {
        Bureaucrat b("Demotable", 145);
        std::cout << "  Before: " << b << std::endl;
        b.demote();
        std::cout << "  After:  " << b << std::endl;
        
        if (b.getGrade() == 146) {
            std::cout << "  ✓ Pass\n" << std::endl;
        } else {
            std::cerr << "  ✗ Fail: Grade should be 146\n" << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: " << e.what() << "\n" << std::endl;
    }
}

void test_demote_boundary()
{
    std::cout << "Test: Demote at boundary (grade 150)" << std::endl;
    try {
        Bureaucrat b("BottomBureaucrat", 150);
        std::cout << "  Before: " << b << std::endl;
        b.demote();
        std::cerr << "  ✗ Fail: Should have thrown exception\n" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "  Caught: " << e.what() << std::endl;
        std::cout << "  ✓ Pass\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: Wrong exception: " << e.what() << "\n" << std::endl;
    }
}

void test_copy_constructor()
{
    std::cout << "Test: Copy constructor" << std::endl;
    try {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);
        
        std::cout << "  Original: " << original << std::endl;
        std::cout << "  Copy:     " << copy << std::endl;
        
        if (copy.getName() == original.getName() && 
            copy.getGrade() == original.getGrade()) {
            
            copy.promote();
            std::cout << "  After promoting copy:" << std::endl;
            std::cout << "    Original: " << original << std::endl;
            std::cout << "    Copy:     " << copy << std::endl;
            
            if (original.getGrade() == 50 && copy.getGrade() == 49) {
                std::cout << "  ✓ Pass\n" << std::endl;
            } else {
                std::cerr << "  ✗ Fail: Deep copy failed\n" << std::endl;
            }
        } else {
            std::cerr << "  ✗ Fail: Copy incorrect\n" << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: " << e.what() << "\n" << std::endl;
    }
}

void test_assignment_operator()
{
    std::cout << "Test: Assignment operator" << std::endl;
    try {
        Bureaucrat b1("First", 10);
        Bureaucrat b2("Second", 100);
        
        std::cout << "  Before assignment:" << std::endl;
        std::cout << "    b1: " << b1 << std::endl;
        std::cout << "    b2: " << b2 << std::endl;
        
        b2 = b1;
        
        std::cout << "  After b2 = b1:" << std::endl;
        std::cout << "    b1: " << b1 << std::endl;
        std::cout << "    b2: " << b2 << std::endl;
        
        if (b2.getGrade() == 10 && b2.getName() == "Second") {
            std::cout << "  Note: b2 keeps its name (const member)" << std::endl;
            std::cout << "  ✓ Pass\n" << std::endl;
        } else {
            std::cerr << "  ✗ Fail: Assignment incorrect\n" << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "  ✗ Fail: " << e.what() << "\n" << std::endl;
    }
}
