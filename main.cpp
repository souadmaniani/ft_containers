#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"
#include <string>


int main () {
	ft::vector<int> myvector(4, 9);
	myvector[0] = 10;
	myvector[1] = 2;
	myvector[2] = 37;
	myvector[3] = 4;

	typedef ft::vector<int>::iterator iter_type;
	ft::vector<int>::iterator iter = myvector.begin();
	ft::reverse_iterator<iter_type> rev_it;
	rev_it = myvector.rbegin() + 1;
	std::cout << "The fourth element from the end is: " << *rev_it << "\n";
	// << *(rev_it - 1) << "|" << *(rev_it1 - 1)<< '\n';
		
  return 0;
}
