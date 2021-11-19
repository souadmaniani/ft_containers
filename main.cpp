#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"
#include <string>


int main ()
{
    ft::vector<std::string> v(8, "souad");
	ft::vector<int>::reverse_iterator it = v.rbegin();
	ft::vector<int>::reverse_iterator it1;
	std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	// it += 1;
	// std::cout << *it << std::endl;
}

