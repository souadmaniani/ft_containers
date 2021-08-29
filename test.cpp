// vector::cbegin/cend
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";

  for (std::vector<int>::iterator it = myvector.cbegin(); it != myvector.cend(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}