#include <iostream>
#include <vector>
#include <string>
// #include <iterator>     // std::reverse_iterator
using namespace std;

int main () {
	vector<int> v(1,1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::reverse_iterator it = v.rbegin();
	std::cout << *it << std::endl;
	it = it + 1;
	std::cout << *it << std::endl;
}