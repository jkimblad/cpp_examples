#include <iostream>
#include <memory>
#include <vector>

// Unique pointer
std::unique_ptr<int> use_unique_pointer() {
	// Since we wont be using "delete" we should also avoid using "new". The
	// solution is to call std::make_unique.
	std::unique_ptr<int> onlyOne = std::make_unique<int>(5);

	return onlyOne;
}

// Shared pointer
std::shared_ptr<int> use_shared_pointer() {
	// Avoid using "new", instead gravitate towards using make_unique and make_shared.
	std::shared_ptr<int> several = std::make_shared<int>(10);
	return several;
}

int main() {
	// Unique pointer
	std::unique_ptr<int> p = use_unique_pointer();
	// Try to overwrite if p points to something saved on the heap
	std::vector<int> temp(100, 2);
	std::cout << *p << std::endl;

	// Shared pointer
	std::shared_ptr<int> p1 = use_shared_pointer();
	std::cout << "Current count 1:" << p1.use_count() << "\n";
	if (true) {
		std::shared_ptr<int> p2 (p1);
		std::cout << "Current count 2:" << p1.use_count() << "\n";
	}
	std::cout << "Current count 1:" << p1.use_count() << "\n";


}
