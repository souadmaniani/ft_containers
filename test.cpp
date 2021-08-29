
// CPP program to illustrate
// auto-initializing of pair STL
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
void swap(T &container, int i, int j)
{
	typename T::value_type temp = container[i];
	container[i] = container[j];
	container[i] = temp;
}

int main()
{
    std::vector<int> t;
	t.push_back(4);
	t.push_back(9);
	swap(t, 0, 1);
	std::cout << t[0] << t[0];
	
    return 0;
}