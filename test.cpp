#include <iostream>
#include <vector>
#include <string>
// #include <iterator>     // std::reverse_iterator
using namespace std;

int main () {
	vector<int> v(1,1);
	v.push_back(9);
	v.push_back(7);
	v.push_back(6);
	v.push_back(1337);
	vector<int>::reverse_iterator it = v.rbegin();
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
}