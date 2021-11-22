#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"
#include <string>

int main () {
	ft::vector<int> myvector(9, 6);
	myvector[8] = 13;
	myvector[1] = 37;
	myvector[0] = 5;
	ft::vector<int>::reverse_iterator from(myvector.rbegin());
	ft::vector<int>::const_iterator from1(myvector.rend());
	std::cout << "myvector has " << from - from1 << " elements.\n";

  return 0;
}