#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"


int main ()
{
 	ft::vector<int> v1;
    ft::vector<int> v2(3, 5);
    ft::vector<int> v3(v2.begin(), v2.end());
	// cout << v[0] << "\n";
	// v[1] = 2;
	// v[2] = 3;
	// ft::vector<int>::reverse_iterator it = v.rbegin();
	// ft::vector<int>::reverse_iterator it1;
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	// it += 1;
	// std::cout << *it << std::endl;
}

