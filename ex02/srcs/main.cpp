
#include <iostream>
#include "Base.class.hpp"

class Wrong : public Base {};

// Generates a random instance of class A, B or C.
Base *generate() {
	// Random number between 0 and 2.
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	std::cout << "Random: " << random << std::endl;
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return new A();;
	}
}

// Displays the type of the instance passed as parameter (with a pointer).
void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Type: A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p)) {
		std::cout << "Type: B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p)) {
		std::cout << "Type: C" << std::endl;
		return;
	}
	std::cout << "Type: Unknown" << std::endl;
}

// Displays the type of the instance passed as parameter (with a reference).
void identify(Base &p) {

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Type: A" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Type: B" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Type: C" << std::endl;
		return;
	} catch (std::exception &e) {}

	std::cout << "Type: Unknown" << std::endl;
}

int main() {
	std::cout << "--- Test with random instance ---" << std::endl;

	Base *base = generate(); // Generate random instance of class A, B or C.
	identify(base); // Identify the type of the instance (with a pointer).
	identify(*base); // Identify the type of the instance (with a reference).
	delete base;

	// Test with Wrong.
	std::cout << std::endl << "--- Test with Wrong ---" << std::endl;
	Wrong wrong;
	identify(&wrong);
	identify(wrong);

	// Test with NULL.
	std::cout << std::endl << "--- Test with NULL ---" << std::endl;
	Base *null = NULL;
	identify(null);

	return 0;
}
