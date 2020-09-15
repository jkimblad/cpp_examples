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
template <int N>
struct Fibonacci {
	static const int result = Fibonacci<N - 1>::result + Fibonacci<N - 2>::result;
};
template <>
struct Fibonacci<1> {
	static const int result = 1;
};
template <>
struct Fibonacci<0> {
	static const int result = 0;
};

int main() {
	// Calculate 5!
	std::cout << Factorial<5>::result << std::endl;

	// Calculate N=5 fibonacci
	std::cout << Fibonacci<0>::result << std::endl;
	std::cout << Fibonacci<1>::result << std::endl;
	std::cout << Fibonacci<2>::result << std::endl;
	std::cout << Fibonacci<3>::result << std::endl;
	std::cout << Fibonacci<4>::result << std::endl;
	std::cout << Fibonacci<5>::result << std::endl;

	return 0;
}
