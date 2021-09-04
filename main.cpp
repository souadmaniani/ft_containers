#include <iostream>
#include "includes/vector.hpp"
#include "includes/iterator.hpp"

int main ()
{
	ft::vector<int> v(5, 7);
	ft::vector<int> v2(v);
	ft::vector<int>::iterator it;
	// it = v.begin();
	it = v.begin() + 1;
	// cout << *it << "\n";
	cout <<  v;
  	return 0;
}
