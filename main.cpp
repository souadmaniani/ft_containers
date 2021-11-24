#include <iostream>
#include "includes/vector.hpp"
#include "vector"
#include <string>

int main () {
	
	std::vector<int>  myvector(4, 8);
	myvector[0]= 5;
	myvector[1]= 6;
	myvector[2]= 7;
	myvector[3]= 13;
	std::cout <<  &myvector[0]<< "|" <<"capacity: "<< myvector.capacity() << "|" <<  "size: " <<  myvector.size()  << std::endl;
	std::vector<int>::iterator it;
	// it = myvector.end() - 1;
  	// it = myvector.insert ( it , 200 );
	myvector.push_back(7);
	myvector.reserve(7);
	std::cout <<  &myvector[0]<< "|" <<"capacity: "<< myvector.capacity() << "|" <<  "size: " <<  myvector.size()  << std::endl;
	
	std::cout << "myvector.at(0): "<<  myvector.at(0) << std::endl;// std::cout << myvector << std::endl;
	while(1) {
		/* code */
	}

  	return 0;
}

