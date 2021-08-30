#include <iostream>
// #include <vector>
#include "includes/vector.hpp"

int main ()
{
	ft::vector v(3, 7);
	v.push_back (13);
	v.push_back (37);
	cout << v;
  return 0;
}