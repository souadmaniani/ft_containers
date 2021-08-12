// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if< std::is_integral<T>::value, bool >::type  is_odd (T i) {
	return bool(i%2);
	}

int main() {

  int * i ;    // code does not compile if type of i is not integral

//   std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;

  return 0;
}