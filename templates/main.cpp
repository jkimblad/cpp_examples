#include <iostream>

// What the core guidelines says about TMP:
// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rt-metameta
template <class T>
T get_max(T a, T b);


// A simple function to return the larger of two inputs
template <class T>
T get_max(T a, T b) {
	return a > b ? a : b;
}

// A simple struct containing a list
template <class T>
struct Vector {
	T vec [];
};

// Example of using c++20 feature concepts
// "Creates a concept refferred to as "Hashable", which is satisfied by any
// type 'T' such that for values 'a' of type 'T', the expression
// std::hash<T>{}(a) compiles and its result is convertible to std::size_t.
template<typename T>
concept Hashable = requires(T a) {
	{std::hash<T>{}(a)} -> std::convertible_to<std::size_t>;
};

// The concept can now be used in a template
template<Hashable T>
void f1(T);

// OR
template<typename T>
	requires Hashable<T>
void f2(T);

//OR
template<typename T>
void f3(T) requires Hashable<T>;


int main() {
	std::cout << get_max(4, 7) << std::endl;
	std::cout << get_max(4.f, 7.f) << std::endl;

	f1(5);
}
