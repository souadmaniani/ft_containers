#include <iostream>
#include "includes/vector.hpp"
#include "includes/iterator.hpp"

int main ()
{
	ft::vector<int> v(5, 7);
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it2;
	it2 = v.begin();
	it = v.end();
	it -= 1;
	
	cout << *it << "\n";
	cout <<  v;
  	return 0;
}
