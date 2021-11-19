#include <type_traits>

template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };
template <class T> struct is_integral : public std::false_type{};
template <> struct is_integral<bool> : public std::true_type{};
template <> struct is_integral<char> : public std::true_type{};
template <> struct is_integral<char16_t> : public std::true_type{};
template <> struct is_integral<char32_t> : public std::true_type{};
template <> struct is_integral<wchar_t> : public std::true_type{};
template <> struct is_integral<signed char> : public std::true_type{};
template <> struct is_integral<short int> : public std::true_type{};
template <> struct is_integral<int> : public std::true_type{};
template <> struct is_integral<long int> : public std::true_type{};
template <> struct is_integral<long long int> : public std::true_type{};
template <> struct is_integral<unsigned char> : public std::true_type{};
template <> struct is_integral<unsigned short int> : public std::true_type{};
template <> struct is_integral<unsigned int> : public std::true_type{};
template <> struct is_integral<unsigned long int> : public std::true_type{};
template <> struct is_integral<unsigned long long int> : public std::true_type{};