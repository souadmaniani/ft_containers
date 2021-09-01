#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char** argv) {
	vector<int> v(3, 7);
	vector<int> v2(3, 7);
	v.push_back (37);
	v.push_back (42);
	// cout << "back: " << v.back() << '\n';
	// v.pop_back();
	// cout << "back: " << v.back() << '\n';
	// v.erase(v.begin());
	v.clear();
	std::cout << v.size() << v.capacity() << v.empty() << std::endl;
	return 0;
}