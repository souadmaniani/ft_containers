#include <iostream>
#include "includes/vector.hpp"
#include "includes/VectorIterator.hpp"
#include "vector"


int main ()
{
	ft::vector<int> first;               
	// ft::vector<int> second (4,10);
	struct MyStruct
	{
		int x;
		char y;

	};
	struct MyStruct t;
	t.x = 1337;
	std::cout << t.x;
	// ft::vector<int> third (second.begin(),second.end());
	// cout << third[0];
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

