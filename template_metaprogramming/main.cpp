#include <iostream>

// Calculating factorial of integer N using TMP
template <int N>
struct Factorial {
	static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<0> {
	static const int result = 1;
};

// Fibonacci series using TMP?

int main() {
	// Calculate 5!
	std::cout << Factorial<5>::result << std::endl;

	return 0;
}
