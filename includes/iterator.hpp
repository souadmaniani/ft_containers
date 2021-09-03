#ifndef ITERATOR_HPP
#define ITERATOR_HPP
using namespace std;

namespace ft
{
    template< class T, class Pointer = T*, class Reference = T&>
    class iterator
    {
    public:
        typedef T value_type;
        typedef Pointer pointer;
        typedef  Reference reference;
    private:
        pointer ptr;
    public:
        iterator() : ptr(0) {}
        iterator(pointer p) : ptr(p) {}
        ~iterator() { }
        iterator(const iterator &x) {
            *this = x;
        }
        iterator& operator=(iterator &x) {
            ptr = x.ptr;
            return (*this);
        }
		bool operator== (const iterator<T>& rhs) {
			return (ptr == rhs.ptr);
		}
		bool operator!= (const iterator<T>& rhs) {
			return (!(*this == rhs));
		}
        reference  operator*() {
            return (*ptr);
        }
    };
}

#endif
