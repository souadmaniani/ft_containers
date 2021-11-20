#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"
#include <string>


int main () {
	ft::vector<int> myvector(3, 9);
	myvector[0] = 11;
	myvector[1] = 12;
	myvector[2] = 13;
	ft::vector<int>::iterator iter_start = myvector.end();
	ft::vector<int>::iterator iter_end = myvector.begin();

	ft::vector<int>::reverse_iterator rev_it(iter_start);
	ft::vector<int>::reverse_iterator rev_it2(iter_end);

	ft::vector<int>::reverse_iterator rev = ++rev_it;

	// for ( rev= rev_it ; rev!= rev_it2 ; ++rev)
	// {
		std::cout << *rev << std::endl;
	// }
  return 0;
}
  