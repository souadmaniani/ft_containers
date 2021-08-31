#include <iostream>
#include <vector>
#include "includes/vector.hpp"

int main ()
{
	ft::vector v(3, 1);
	v.push_back (13);
	v.push_back (37);
	ft::vector v2(4);
	if (v == v2)
		std::cout << "v equal v2" << std::endl;
	else
		std::cout << "not equal" << std::endl;
	cout << v;
	v = v2;
	cout << v;
  return 0;
}
