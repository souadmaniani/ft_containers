#include <iostream>
#include "includes/vector.hpp"
#include "vector"
#include <string>

int main () {
	ft::vector<int> myvector(4, 9);
	myvector[0] = 4;
	myvector[1] = 5;
	myvector[2] = 6;
	myvector.reserve(6);
	myvector[3] = 13;
	myvector[4] = 37;
	// myvector.resize(40, 8);
	for (size_t i = 0; i < myvector.capacity(); i++)
	{
		std::cout << myvector[i] << std::endl;
	}
	std::cout << "capacity: "<< myvector.capacity() << "|" <<  "size: " <<  myvector.size()  << std::endl;
	// std::cout << myvector << std::endl;
	// No, resize ing to a smaller size will never reallocate.
	// while(1) {
	// 	/* code */
	// }
	
  	return 0;
}

