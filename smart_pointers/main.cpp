#include <iostream>
#include <memory>
#include <vector>

// Shared pointer
std::unique_ptr<int> use_unique_pointer() {
	// Since we wont be using "delete" we should also avoid using "new". The
	// solution is to call std::make_unique.
	std::unique_ptr<int> onlyOne = std::make_unique<int>(5);

	return onlyOne;
}

int main() {
	// Shared pointer
	std::unique_ptr<int> p = use_unique_pointer();
	// Try to overwrite if p points to something saved on the heap
	std::vector<int> temp(100, 2);
	std::cout << *p << std::endl;
}
