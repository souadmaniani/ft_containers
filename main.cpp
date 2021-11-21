#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"
#include <string>

// class MyClass {
//   public:
//     int n1;
//     int n2;
// };

int main() {

	ft::vector<int> myVector(4, 5);
	// ft::vector<int>::reverse_iterator t(myVector.begin());
	// ft::vector<int>::reverse_iterator t2(myVector.begin());
	// if (t == t2)
	// std::cout << "/* message */" << std::endl;
	ft::vector<int>::iterator i(myVector.begin());
	ft::vector<int>::iterator i1(myVector.begin());
	ft::vector<int>::const_iterator ic(myVector.begin());
	ft::vector<int>::const_iterator tmp(ic);
	ft::vector<int>::const_iterator ic1(myVector.begin());
	if (i == i1)
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not Equal" << std::endl;
//   myVector[0] = 37;
//   myVector[1] = 13;
//   myVector[2] = 8;
//   myVector[3] = 9;
//   typedef ft::vector<int>::iterator iter_type;
//   ft::reverse_iterator<iter_type> rev_iter = myVector.rbegin();

//   std::cout << *rev_iter << std::endl;
//   std::cout << "************" << std::endl;
//   std::cout << rev_iter[0] << std::endl;
//   std::cout << rev_iter[1] << std::endl;
//   std::cout << rev_iter[2] << std::endl;
//   std::cout << rev_iter[3] << std::endl;
}
