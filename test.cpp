#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int main() {
	// vector<int> v(2, 7);
	vector<int> v;
	v.push_back(13);
	iterator< std::random_access_iterator_tag, long, long, const long*, long > it1;
	iterator< std::random_access_iterator_tag, long, long, const long*, long > it2;
	// if (it1 == it2)
	// 	cout << "equality\n";
	return 0;
}