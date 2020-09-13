#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

std::vector<int> generate_random_vector(unsigned int size,
					const unsigned int min,
					const unsigned int max);

// Lambda functions work like anonymous functions in that they dont have an
// explicit name for the programmer to call. They take parameters, perform some
// computation and return some data.
//
// Lambda functions can be defined on the form [](){}, where [] is used to pass
// objects from the current scope into the function. () is used to pass function
// parameters to the lambda function and {} defines the behaviour of the lambda
// function. An optional return type can also be specified using []()->int{}.

int main() {
	std::vector<int> randVector = generate_random_vector(10, 0, 50);

	// Sort a list using simple lambda function
	std::sort(randVector.begin(), randVector.end(),
		  [](int x, int y) -> bool { return x < y; });
}

std::vector<int> generate_random_vector(unsigned int size,
					const unsigned int min,
					const unsigned int max) {
	std::vector<int> retVector;
	// Seed rand
	std::srand(std::time(nullptr));

	while (size > 0) {
		retVector.push_back(min + (std::rand() % (max + 1 - min)));
		size--;
	}

	return retVector;
}
