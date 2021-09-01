#include <iostream>
#include "includes/vector.hpp"

int main ()
{
	ft::vector v;
	ft::vector v2(3, 7);
	v.push_back (37);
	v.push_back (42);
	cout << v;
	// cout << "front: " << v.front() << '\n';
	// cout << "back: " << v.back() << '\n';
	// v.pop_back();
	// cout << "back: " << v.back() << '\n';
	// if (v != v2)
	// 	std::cout << "******true***" << std::endl;
	// v.erase(0);
	v.clear();
	cout << v;
  return 0;
}
