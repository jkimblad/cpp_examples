#include <iostream>

// What the core guidelines says about TMP:
// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rt-metameta
template <class T>
T get_max(T a, T b);

int main() {
	std::cout << get_max(4, 7) << std::endl;
	std::cout << get_max(4.f, 7.f) << std::endl;
}

// A simple function to return the larger of two inputs
template <class T>
T get_max(T a, T b) {
	return a > b ? a : b;
}
