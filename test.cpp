#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int main() {
	// vector<int> v(9, 2);
	// vector<int>::iterator it;
	// vector<int>::iterator res;
	// vector<int>::iterator o;
	// int k;

	// it = v.begin();
	// it = it + 1;
	// res = it + 1;
	// it++;
	vector<int> v(5, 7);
	vector<int>::iterator it;
	vector<int>::iterator it2;
	vector<int>::difference_type diff;

	it = v.begin();
	it2 = v.end();
	it +=  1;
	cout << *it << "\n";
	diff = it - it2;
	if (it < it2)
		cout << "it is smaller\n";
	cout << diff << "\n";
	// cout << it:pointer;
	// cout <<  v;

}