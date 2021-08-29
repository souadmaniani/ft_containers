# enable_if
	template <bool Cond, class T = void> struct enable_if;
- SFINAE: Substitution Failure is not an Error, means that if the compiler fails to specialize a template with a given template argument list, it does not issue an error. It does when it cannot find any suitable function/class to be called/instantiated (either due to a lack of suitably declared functions/classes or an error during instantiation).
- [SFINAE] (https://www.thewolfsound.com/sfinae-substitution-failure-is-not-an-error/)
- enable_if is an extremely useful tool. It's so useful because it's a key part in using type traits (For example, given a generic type T — it could be int, bool, std::vector or whatever you want — with type traits you can ask the compiler some questions: is it an integer? Is it a function? Is it a pointer? Or maybe a class? Does it have a destructor? Can you copy it? Will it throw exceptions? ... and so on), a way to restrict templates to types that have certain properties. Without enable_if, templates are a rather blunt "catch-all" tool. If we define a function with a template argument, this function will be invoked on all possible types. Type traits and enable_if let us create different functions that act on different kinds of types, while still remaining generic.
# is_integral
	template <class T> struct is_integral;
- Trait class that identifies whether T is an integral type.
	fundamental integral types : bool, char, char16_t, char32_t, wchar_t, signed char, short int, int,long int,
	long long int, unsigned char, unsigned short int, unsigned int, unsigned long int, unsigned long long int.
# lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2);
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp);
- (https://www.cplusplus.com/reference/algorithm/lexicographical_compare/)
# pair
	default (1)		pair();
	copy (2)		template<class U, class V> pair (const pair<U,V>& pr);
	initialization (3)	pair (const first_type& a, const second_type& b);
- (https://www.geeksforgeeks.org/pair-in-cpp-stl/)
# make_pair
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y);
- Construct pair object
# C++ keywords: typename
### Usage
- In the template parameter list of a template declaration, typename can be used as an alternative to class to declare type template parameters.
- Inside a declaration or a definition of a template, typename can be used to declare that a dependent qualified name is a type.
- Example: a swap function that accepts a container (templated), and two indices to swap, u could use the value_type definition to define a temp variable.
# allocator
	template <class T> class allocator;
- Allocators are objects responsible for encapsulating memory management.
- allocator is the memory allocator for the STL containers
- std::allocator separate the memory allocation and de-allocation from the initialization and destruction.
- use case: (https://www.mashen.zone/thread-3676500.htm)
