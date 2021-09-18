#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"

int main ()
{
	ft::vector<int> v(1,1);
	ft::vector<int>::reverse_iterator it = v.rbegin();
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
}
