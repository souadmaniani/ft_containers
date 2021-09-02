#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char** argv) {
	vector<int> v(3, 7);
	vector<int> v2(3, 7);
	v.insert(v.end(), 113);
	cout << v[3] << '\n';
	return 0;
}