#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormValidConstruction();
void testFormInvalidConstruction();
void testFormCopyConstructor();
void testFormAssignmentOperator();
void testFormBeSignedSuccess();
void testFormBeSignedFailure();
void testBureaucratSignForm();
void testFormOutputStream();
void testEdgeCases();


int main() {
	std::cout << "\n=== Form Tests ===\n" << std::endl;
	
	testFormValidConstruction();
	testFormInvalidConstruction();
	testFormCopyConstructor();
	testFormAssignmentOperator();
	testFormBeSignedSuccess();
	testFormBeSignedFailure();
	testBureaucratSignForm();
	testFormOutputStream();
	testEdgeCases();
	
	std::cout << "\n=== All Tests Completed ===\n" << std::endl;
	
	return 0;
}


void testFormValidConstruction() {
	std::cout << "\n--- Test: Form Valid Construction ---" << std::endl;
	
	try {
		Form f1("Tax Form", 50, 25);
		if (f1.getName() == "Tax Form" && f1.getGradeToSign() == 50 
			&& f1.getGradeToExecute() == 25 && f1.getIsSigned() == false)
			std::cout << "✓ Created valid form with grades 50/25" << std::endl;
		else
			std::cout << "✗ Form attributes not set correctly" << std::endl;
		
		Form f2("Simple Form", 1, 150);
		std::cout << "✓ Created valid form with grades 1/150" << std::endl;
		
		Form f3("Medium Form", 75, 75);
		std::cout << "✓ Created valid form with grades 75/75" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
	}
}

void testFormInvalidConstruction() {
	std::cout << "\n--- Test: Form Invalid Construction ---" << std::endl;
	
	// Test grade to sign too high
	try {
		Form f("InvalidSign", 0, 50);
		std::cout << "✗ Should have thrown GradeTooHighException for sign grade 0" << std::endl;
	} catch (Form::GradeTooHighException& e) {
		std::cout << "✓ Correctly threw GradeTooHighException for sign grade 0" << std::endl;
	} catch (...) {
		std::cout << "✗ Wrong exception type" << std::endl;
	}
	
	// Test grade to sign too low
	try {
		Form f("InvalidSign", 151, 50);
		std::cout << "✗ Should have thrown GradeTooLowException for sign grade 151" << std::endl;
	} catch (Form::GradeTooLowException& e) {
		std::cout << "✓ Correctly threw GradeTooLowException for sign grade 151" << std::endl;
	} catch (...) {
		std::cout << "✗ Wrong exception type" << std::endl;
	}
	
	// Test grade to execute too high
	try {
		Form f("InvalidExec", 50, 0);
		std::cout << "✗ Should have thrown GradeTooHighException for exec grade 0" << std::endl;
	} catch (Form::GradeTooHighException& e) {
		std::cout << "✓ Correctly threw GradeTooHighException for exec grade 0" << std::endl;
	} catch (...) {
		std::cout << "✗ Wrong exception type" << std::endl;
	}
	
	// Test grade to execute too low
	try {
		Form f("InvalidExec", 50, 151);
		std::cout << "✗ Should have thrown GradeTooLowException for exec grade 151" << std::endl;
	} catch (Form::GradeTooLowException& e) {
		std::cout << "✓ Correctly threw GradeTooLowException for exec grade 151" << std::endl;
	} catch (...) {
		std::cout << "✗ Wrong exception type" << std::endl;
	}
}

void testFormCopyConstructor() {
	std::cout << "\n--- Test: Form Copy Constructor ---" << std::endl;
	
	try {
		Form original("Original Form", 50, 25);
		Form copy(original);
		
		if (copy.getName() == "Original Form" && copy.getGradeToSign() == 50 
			&& copy.getGradeToExecute() == 25 && copy.getIsSigned() == false)
			std::cout << "✓ Copy constructor works correctly" << std::endl;
		else
			std::cout << "✗ Copy constructor failed to copy attributes" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}
}

void testFormAssignmentOperator() {
	std::cout << "\n--- Test: Form Assignment Operator ---" << std::endl;
	
	try {
		Form f1("Form1", 50, 25);
		Form f2("Form2", 100, 75);
		
		f2 = f1;
		std::cout << "✓ Assignment operator works" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}
}

void testFormBeSignedSuccess() {
	std::cout << "\n--- Test: Form Signing - Success Cases ---" << std::endl;
	
	try {
		Form form("Permission Form", 50, 25);
		Bureaucrat highGrade("Boss", 30);
		
		form.beSigned(highGrade);
		if (form.getIsSigned() == true)
			std::cout << "✓ Form signed successfully by bureaucrat with sufficient grade" << std::endl;
		else
			std::cout << "✗ Form was not signed" << std::endl;
		
		Form form2("Easy Form", 100, 50);
		Bureaucrat exactGrade("Worker", 100);
		form2.beSigned(exactGrade);
		if (form2.getIsSigned() == true)
			std::cout << "✓ Form signed successfully by bureaucrat with exact grade" << std::endl;
		else
			std::cout << "✗ Form was not signed" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
	}
}

void testFormBeSignedFailure() {
	std::cout << "\n--- Test: Form Signing - Failure Cases ---" << std::endl;
	
	try {
		Form form("High Level Form", 10, 5);
		Bureaucrat lowGrade("Intern", 50);
		
		try {
			form.beSigned(lowGrade);
			std::cout << "✗ Should have thrown GradeTooLowException" << std::endl;
		} catch (Form::GradeTooLowException& e) {
			if (form.getIsSigned() == false)
				std::cout << "✓ Correctly threw exception for insufficient grade" << std::endl;
			else
				std::cout << "✗ Form was incorrectly signed" << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
	}
}

void testBureaucratSignForm() {
	std::cout << "\n--- Test: Bureaucrat signForm Method ---" << std::endl;
	
	try {
		// Success case
		Form form1("Request Form", 50, 25);
		Bureaucrat b1("Manager", 30);
		std::cout << "Attempting to sign form:" << std::endl;
		b1.signForm(form1);
		if (form1.getIsSigned() == true)
			std::cout << "✓ signForm succeeded with sufficient grade\n" << std::endl;
		else
			std::cout << "✗ signForm failed unexpectedly\n" << std::endl;
		
		// Failure case
		Form form2("Executive Form", 10, 5);
		Bureaucrat b2("Junior", 50);
		std::cout << "Attempting to sign form:" << std::endl;
		b2.signForm(form2);
		if (form2.getIsSigned() == false)
			std::cout << "✓ signForm failed with insufficient grade" << std::endl;
		else
			std::cout << "✗ signForm succeeded unexpectedly" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
	}
}

void testFormOutputStream() {
	std::cout << "\n--- Test: Form Output Stream ---" << std::endl;
	
	try {
		Form f1("Unsigned Form", 50, 25);
		std::cout << f1 << std::endl;
		
		Bureaucrat b("Signer", 30);
		f1.beSigned(b);
		std::cout << f1 << std::endl;
		
		std::cout << "✓ Output stream operator works" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}
}

void testEdgeCases() {
	std::cout << "\n--- Test: Edge Cases ---" << std::endl;
	
	try {
		// Test with grade 1 (highest)
		Bureaucrat topBureaucrat("CEO", 1);
		Form topForm("Top Secret", 1, 1);
		topBureaucrat.signForm(topForm);
		if (topForm.getIsSigned() == true)
			std::cout << "✓ Grade 1 bureaucrat can sign grade 1 form" << std::endl;
		else
			std::cout << "✗ Grade 1 bureaucrat failed to sign grade 1 form" << std::endl;
		
		// Test with grade 150 (lowest)
		Bureaucrat bottomBureaucrat("Intern", 150);
		Form easyForm("Coffee Order", 150, 150);
		bottomBureaucrat.signForm(easyForm);
		if (easyForm.getIsSigned() == true)
			std::cout << "✓ Grade 150 bureaucrat can sign grade 150 form" << std::endl;
		else
			std::cout << "✗ Grade 150 bureaucrat failed to sign grade 150 form" << std::endl;
		
		// Test signing already signed form
		Form alreadySigned("Signed Form", 100, 50);
		Bureaucrat b1("First", 50);
		Bureaucrat b2("Second", 50);
		b1.signForm(alreadySigned);
		b2.signForm(alreadySigned);
		std::cout << "✓ Can attempt to sign already signed form" << std::endl;
	} catch (std::exception& e) {
		std::cout << "✗ Exception: " << e.what() << std::endl;
	}
}
