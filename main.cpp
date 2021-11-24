#include <iostream>
#include "includes/vector.hpp"
#include "vector"
#include <string>

int main () {
	
	ft::vector<int>  myvector(4, 8);
	myvector[0]= 5;
	myvector[1]= 6;
	myvector[2]= 7;
	myvector[3]= 13;
	// std::cout <<  &myvector[0]<< "|" <<"capacity: "<< myvector.capacity() << "|" <<  "size: " <<  myvector.size()  << std::endl;
	ft::vector<int>::iterator it;
	it = myvector.begin();
  	it = myvector.insert ( it , 200 );
	// std::cout <<  &myvector[0]<< "|" <<"capacity: "<< myvector.capacity() << "|" <<  "size: " <<  myvector.size()  << std::endl;
	// int i = -1;
	// while(++i < myvector.size()) {
	// 	std::cout << myvector[i] << "|";
	// }
	// std::cout << "myvector.at(0): "<<  myvector.at(0) << std::endl;// std::cout << myvector << std::endl;
	// while(1) {
	// 	/* code */
	// }

  	return 0;
}

