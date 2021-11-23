#include <iostream>
#include "includes/vector.hpp"
#include "vector"
#include <string>

int main () {
	ft::vector<int> myvector(9, 6);
	myvector[8] = 13;
	myvector[1] = 37;
	myvector[0] = 5;
	ft::vector<int>::reverse_iterator from1 = myvector.rbegin();
	ft::vector<int>::reverse_iterator from2 = myvector.rend();
	if (from1 > from2)
		std::cout << ">" << std::endl;
	else
	{
		std::cout << "l3akss" << std::endl;
	}
  return 0;
}

