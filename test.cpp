
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
using namespace std;

// template<>
// struct allocator<void>;
//        // default allocator for ints
//         std::allocator<int> alloc;
//         int* p = alloc.allocate(1);
//         alloc.deallocate(p, 1);


template<typename T>
std::string get_iterator_type (T it) {
        // __normal_iterator<int *, vector<int, allocator<int> > > >
        if      (typeid (std::iterator_traits<__normal_iterator<int *, vector<int, allocator<int> > > >::iterator_category) == typeid (std::input_iterator_tag))	  return "Input";
        // else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::output_iterator_tag))        return "Output";
        // else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::forward_iterator_tag))       return "Forward";
        // else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::bidirectional_iterator_tag)) return "Bidirectional";
        // else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::random_access_iterator_tag)) return "Random Access";

        return "missing";
}

int main () {

	std::vector<int> v;
	// std::deque<int> d;
	// std::forward_list<int> fl;
	// std::list<int> l;

	// std::set<int> s;
	// std::map<int, int> m;
	

	std::vector<int>::iterator it1 = v.begin  ();
	// std::deque<int>::iterator it2 = d.begin  ();
	// std::forward_list<int>::iterator it3 = fl.begin ();
	// std::list<int>::iterator it4 = l.begin  ();

	// std::set<int>::iterator it5 = s.begin  ();
	// std::map<int, int>::iterator it6 = m.begin  ();

	std::cout << "\nSequence Containers:\n\n";
	std::cout << "vector::begin        () returns a " << get_iterator_type (it1) << " Iterator.\n";
	// std::cout << "deque::begin         () returns a " << get_iterator_type (it2) << " Iterator.\n";
	// std::cout << "forward_list::begin  () returns a " << get_iterator_type (it3) << " Iterator.\n";

	// std::cout << "\nAssociative Containers:\n\n";
	// std::cout << "set::begin           () returns a " << get_iterator_type (it5) << " Iterator.\n";
	// std::cout << "map::begin           () returns a " << get_iterator_type (it6) << " Iterator.\n";
	return 0;
}