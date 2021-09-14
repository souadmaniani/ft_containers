#ifndef ITERATOR_HPP
#define ITERATOR_HPP
using namespace std;

namespace ft
{
    template<class V>
    class ConstIterator
    {
        public:
        typedef V value_type;
	    typedef const V* const_pointer;
        typedef  const V& const_reference;
        // typedef Distance difference_type;
        private:
            const_pointer ptr;
        public:
            ConstIterator() : ptr(0) {}
            ConstIterator( const_pointer p) : ptr(p) {
                std::cout << "ConstIterator: constructor" << std::endl;
            }
            ~ConstIterator() { }
            ConstIterator(const ConstIterator &x) {
                std::cout << "ConstIterator: copy" << std::endl;
                *this = x;
            }
            ConstIterator& operator=(const ConstIterator &x) {
                std::cout << "ConstIterator: assignation" << std::endl;
                ptr = x.ptr;
                return (*this);
            }
            const_reference operator*() {
                return (*ptr);
            }
    };

    template< class T>
    class Iterator : public ConstIterator<T>
    {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef  T& reference;
    private:
        pointer ptr;
    public:
        Iterator() : ptr(0) {}
        Iterator(pointer p) : ptr(p) {
            std::cout << "Iterator: constructor" << std::endl;
        }
        ~Iterator() { }
        Iterator(const Iterator &x) {
            std::cout << "Iterator: copy" << std::endl;
            *this = x;
        }
        Iterator& operator=(const Iterator &x) {
            std::cout << "Iterator: assignation" << std::endl;
            ptr = x.ptr;
            return (*this);
        }
		bool operator== (const Iterator<T>& rhs) {
			return (ptr == rhs.ptr);
		}
		bool operator!= (const Iterator<T>& rhs) {
			return (!(*this == rhs));
		}
        reference operator*() {
            return (*ptr);
        }
        pointer operator->(){
            return (ptr);
        }
        Iterator& operator++() {
            ++ptr;
            return (*this);
        }
        Iterator& operator--() {
            --ptr;
            return (*this);
        }
        // Iterator operator+(difference_type n) {
        //     Iterator t(*this);
        //     t.ptr += n;
        //     return (t);
        // }
        // Iterator operator-(difference_type n) {
        //     Iterator t (*this);
        //     t.ptr -= n;
        //     return (t);
        // }
        // Iterator& operator+=(difference_type n) {
        //     ptr = ptr + n;
        //     return (*this);
        // }
        // Iterator& operator-=(difference_type n) {
        //     ptr = ptr - n;
        //     return (*this);
        // }
        // difference_type operator-(Iterator & j) {
        //     return (*this - j);
        // }
        // bool operator<(const Iterator& rhs) {
        //     return (ptr < rhs.ptr);
        // }
        // bool operator>(const Iterator& rhs) {
        //     return (ptr > rhs.ptr);
        // }
        // bool operator<=(const Iterator& rhs) {
        //     return (ptr <= rhs.ptr);
        // }
        // bool operator>=(const Iterator& rhs) {
        //     return (ptr >= rhs.ptr);
        // }
        // value_type operator[] (difference_type n) {
        //     return (ptr[n]);
        // }
        // friend ostream & operator<<(ostream & o, Iterator const & rhs);
    };
}

#endif
