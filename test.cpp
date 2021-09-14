#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	std::vector<int> d;
   	std::vector<int>::const_iterator i =  d.begin();
   	std::vector<int>::iterator itr =  d.end();
   	i = itr;
}