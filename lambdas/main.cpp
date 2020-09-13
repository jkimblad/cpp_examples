#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
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

	// Calculate the sum of all elements in a vector
	// We can use a single & in the capture list to pass in references to
	// all objects in current scope to the lambda function such that they
	// can be accessed from within it.
	unsigned int sum = 0;
	std::vector<int> randVector2 = generate_random_vector(20, 0, 50);
	std::for_each(randVector2.begin(), randVector2.end(),
		      [&](int x) -> void { sum += x; });
	// std::cout << sum << std::endl;

	// Create a list of values that are divisible by $divisor from a list
	// of random values
	std::vector<int> randVector3 = generate_random_vector(20, 0, 50);
	std::vector<int> divisible;
	int divisor = 1;
	// std::cin >> divisor;
	std::copy_if(randVector3.begin(), randVector3.end(),
		     std::back_inserter(divisible),
		     [divisor](int x) -> bool { return !(x % divisor); });
	// for (const auto val : divisible) std::cout << val << std::endl;

	// Multiply all values inside of a vector
	std::vector<int> randVector4 = generate_random_vector(20, 0, 50);
	std::vector<int> multiVector;
	std::for_each(randVector4.begin(), randVector4.end(),
		      [&](int x) -> void { multiVector.push_back(x * 2); });
	// for (const auto val : multiVector) std::cout << val << std::endl;

	// Perform a transformation of two vectors into one using std::transform
	// Using std::back_inserter(result) for the result vector seems to give
	// some strange behavior
	std::vector<int> vec1 = {1, 2, 3, 4, 5};
	std::vector<int> vec2 = {2, 4, 6, 8, 10};
	std::vector<int> result(5);
	std::transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(),
		       [](int x, int y) -> int { return x + y; });
	// for (const auto val : result) std::cout << val << std::endl;

	// Recursive lambda function using a ternary operator
	// For the function to call itself we save it as a std::function and
	// pass itself into its capture list
	std::function<unsigned int(unsigned int)> fib =
	    [&fib](unsigned int n) -> unsigned int {
		return n < 2 ? n : fib(n - 1) + fib(n - 2);
	};
	std::cout << fib(6) << std::endl;  // 8
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
