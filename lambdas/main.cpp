#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
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
	// Sort a list using simple lambda function
	// < sorts in ascending order
	// > sorts in descending order
	std::vector<int> randVector = generate_random_vector(10, 0, 50);
	std::sort(randVector.begin(), randVector.end(),
		  [](const int x, const int y) -> bool { return x > y; });
	// for (const auto val : randVector) std::cout << val << std::endl;

	// Extract all even or odd values from a vextor
	// x % 2 returns odd values
	// !(x % 2) returns odd values
	std::vector<int> randVector1 = generate_random_vector(20, 0, 50);
	std::vector<int> evenVector;
	std::copy_if(randVector1.begin(), randVector1.end(),
		     std::back_inserter(evenVector),
		     [](const int x) -> bool { return (x % 2); });
	// for (const auto val : evenVector) std::cout << val << std::endl;
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
