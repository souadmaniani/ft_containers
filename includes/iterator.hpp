#ifndef ITERATOR_HPP
#define ITERATOR_HPP
using namespace std;

namespace ft
{
    template< class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator
    {
    public:
        typedef T value_type;
        typedef Pointer pointer;
        typedef  Reference reference;
        typedef Distance difference_type;
    private:
        pointer ptr;
    public:
        iterator() : ptr(0) {}
        iterator(pointer p) : ptr(p) {}
        ~iterator() { }
        iterator(const iterator &x) {
            *this = x;
        }
        iterator& operator=(const iterator &x) {
            ptr = x.ptr;
            return (*this);
        }
		bool operator== (const iterator<T>& rhs) {
			return (ptr == rhs.ptr);
		}
		bool operator!= (const iterator<T>& rhs) {
			return (!(*this == rhs));
		}
        reference operator*() {
            return (*ptr);
        }
        pointer operator->(){
            return (ptr);
        }
        iterator& operator++() {
            ++ptr;
            return (*this);
        }
        iterator& operator--() {
            --ptr;
            return (*this);
        }
        iterator operator+(difference_type n) {
            iterator t(*this);
            t.ptr += n;
            return (t);
        }
        iterator operator-(difference_type n) {
            iterator t (*this);
            t.ptr -= n;
            return (t);
        }
        iterator& operator+=(difference_type n) {
            ptr = ptr + n;
            return (*this);
        }
        iterator& operator-=(difference_type n) {
            ptr = ptr - n;
            return (*this);
        }
        difference_type operator-(iterator & j) {
            return (*this - j);
        }
        bool operator<(const iterator& rhs) {
            return (ptr < rhs.ptr);
        }
        bool operator>(const iterator& rhs) {
            return (ptr > rhs.ptr);
        }
        bool operator<=(const iterator& rhs) {
            return (ptr <= rhs.ptr);
        }
        bool operator>=(const iterator& rhs) {
            return (ptr >= rhs.ptr);
        }
        value_type operator[] (difference_type n) {
            return (ptr[n]);
        }
    };
}

#endif
