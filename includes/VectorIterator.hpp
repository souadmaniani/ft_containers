#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP
using namespace std;

namespace ft
{
    template< class T>
    class Iterator
    {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef  T& reference;
		typedef std::ptrdiff_t difference_type;
        // Implicit conversions are performed whenever an expression of some type T1
        // is used in context that does not accept that type, but accepts some other type T2; in particular:
		// when the expression is used as an operand with an operator that expects T2
        operator Iterator<const T>() const {
            std::cout << "/* ****** operator ******* */" << std::endl;
			return (Iterator<const T>(ptr)); 
		}
    protected:
        pointer ptr;
    public:
        Iterator() : ptr(0) {}
        Iterator(pointer p) : ptr(p) {
            std::cout << "Iterator: constructor" << std::endl;
        }
        ~Iterator() { }
        Iterator(const Iterator &x) {
            // std::cout << "Iterator: copy" << std::endl;
            *this = x;
        }
        Iterator& operator=(const Iterator &x) {
            // std::cout << "Iterator: assignation" << std::endl;
            ptr = x.ptr;
            return (*this);
        }
		bool operator== (const Iterator<T>& rhs) {
			return (ptr == rhs.ptr);
		}
		bool operator!= (const Iterator<T>& rhs) {
			return (!(*this == rhs));
		}
        reference operator*() const {
            return (*ptr);
        }
        pointer operator->()  const{
            return (ptr);
        }
        Iterator& operator++() {
            ++ptr;
            return (*this);
        }
        Iterator operator++(int) {
            Iterator t(*this);
            ++(*this);
            return (t);
        }
        Iterator& operator--() {
            --ptr;
            return (*this);
        }
        Iterator operator--(int) {
            Iterator t(*this);
            --(*this);
            return (t);
        }
        Iterator operator+(difference_type n) {
            Iterator t(*this);
            t.ptr += n;
            return (t);
        }
        Iterator operator-(difference_type n) {
            Iterator t(*this);
            t.ptr -= n;
            return (t);
        }
        Iterator& operator+=(difference_type n) {
            ptr = ptr + n;
            return (*this);
        }
        Iterator& operator-=(difference_type n) {
            ptr = ptr - n;
            return (*this);
        }
        difference_type operator-(Iterator & j) {
            return (*this - j);
        }
        bool operator<(const Iterator& rhs) {
            return (ptr < rhs.ptr);
        }
        bool operator>(const Iterator& rhs) {
            return (ptr > rhs.ptr);
        }
        bool operator<=(const Iterator& rhs) {
            return (ptr <= rhs.ptr);
        }
        bool operator>=(const Iterator& rhs) {
            return (ptr >= rhs.ptr);
        }
        value_type operator[] (difference_type n) {
            return (ptr[n]);
        }
    };
    
 
}

#endif
