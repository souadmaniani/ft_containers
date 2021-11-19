#include <type_traits>

template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };


template <class T>
typename enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}


int main() {

  short int i = 1;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;

  return 0;
}