
#include <iostream>

#include "Bureaucrat.class.hpp"

void	test_create_bureaucrat_with_grade(int grade) {
	std::cout << std::endl << "--- TEST: create with grade " << grade << " ---" << std::endl;

	try {
		Bureaucrat bureaucrat("Bernard", grade);
		std::cout << bureaucrat;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_create_bureaucrat_with_grade_and_increment(int grade, int nbIncrementations) {
	std::cout << std::endl << "--- TEST: create with grade " << grade << " and increment " << nbIncrementations << " times ---" << std::endl;

	try {
		Bureaucrat bureaucrat("Bernard", grade);
		std::cout << bureaucrat;
		for (int i = 0; i < nbIncrementations; i++) {
			bureaucrat.incrementGrade();
			std::cout << bureaucrat;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_create_bureaucrat_with_grade_and_decrement(int grade, int nbDecrementations) {
	std::cout << std::endl << "--- TEST: create with grade " << grade << " and decrement " << nbDecrementations << " times ---" << std::endl;

	try {
		Bureaucrat bureaucrat("Bernard", grade);
		std::cout << bureaucrat;
		for (int i = 0; i < nbDecrementations; i++) {
			bureaucrat.decrementGrade();
			std::cout << bureaucrat;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_copy_bureaucrat() {
	std::cout << std::endl << "--- TEST: copy ---" << std::endl;

	Bureaucrat bureaucrat("Bernard", 4);
	std::cout << bureaucrat;
	Bureaucrat bureaucratCopy(bureaucrat);
	std::cout << bureaucratCopy;
}

void	test_copy_with_affection() {
	std::cout << std::endl << "--- TEST: copy with affection ---" << std::endl;

	Bureaucrat bureaucrat("Bernard", 1);
	std::cout << bureaucrat;
	Bureaucrat bureaucratCopy("Jean", 150);
	std::cout << bureaucratCopy;
	bureaucratCopy = bureaucrat;
	std::cout << bureaucratCopy;
}

int main() {
	test_create_bureaucrat_with_grade(150);
	test_create_bureaucrat_with_grade(1);
	test_create_bureaucrat_with_grade(0);
	test_create_bureaucrat_with_grade(151);

	test_create_bureaucrat_with_grade_and_increment(2, 2);
	test_create_bureaucrat_with_grade_and_increment(1, 3);

	test_create_bureaucrat_with_grade_and_decrement(149, 2);
	test_create_bureaucrat_with_grade_and_decrement(150, 3);

	test_copy_bureaucrat();
	test_copy_with_affection();

	return 0;
}
