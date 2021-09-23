#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"

int main ()
{
	ft::vector<int> v(3,1);
	v[1] = 2;
	v[2] = 3;
	ft::vector<int>::reverse_iterator it = v.rbegin();
	ft::vector<int>::reverse_iterator it1;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	it += 1;
	std::cout << *it << std::endl;
	
}
