#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"

int main ()
{
	ft::vector<int> v(2,1337);
	ft::vector<int>::reverse_iterator it = v.rbegin();
	for (it = v.rbegin(); it != v.rend(); it--)
	{
		std::cout << *it << std::endl;
	}
}
