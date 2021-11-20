#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

namespace ft
{
    template< class T>
    class VectorIterator
    {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef  T& reference;
		typedef std::ptrdiff_t difference_type;
        // Implicit conversions are performed whenever an expression of some type T1
        // is used in context that does not accept that type, but accepts some other type T2; in particular:
		// when the expression is used as an operand with an operator that expects T2
        operator VectorIterator<const T>() const {
            std::cout << "/* ****** operator ******* */" << std::endl;
			return (VectorIterator<const T>(ptr)); 
		}
    protected:
        pointer ptr;
    public:
        VectorIterator() : ptr(0) {}
        VectorIterator(pointer p) : ptr(p) {
        }
        ~VectorIterator() { }
        VectorIterator(const VectorIterator &x) {
            // std::cout << "VectorIterator: copy" << std::endl;
            *this = x;
        }
        VectorIterator& operator=(const VectorIterator &x) {
            // std::cout << "VectorIterator: assignation" << std::endl;
            ptr = x.ptr;
            return (*this);
        }
		bool operator== (const VectorIterator<T>& rhs) {
			return (ptr == rhs.ptr);
		}
		bool operator!= (const VectorIterator<T>& rhs) {
			return (!(*this == rhs));
		}
        reference operator*() const {
            return (*ptr);
        }
        pointer operator->()  const{
            return (ptr);
        }
        VectorIterator& operator++() {
            ++ptr;
            return (*this);
        }
        VectorIterator operator++(int) {
            VectorIterator t(*this);
            ++(*this);
            return (t);
        }
        VectorIterator& operator--() {
            --ptr;
            return (*this);
        }
        VectorIterator operator--(int) {
            VectorIterator t(*this);
            --(*this);
            return (t);
        }
        VectorIterator operator+(difference_type n) {
            VectorIterator t(*this);
            t.ptr += n;
            return (t);
        }
        VectorIterator operator-(difference_type n) {
            VectorIterator t(*this);
            t.ptr -= n;
            return (t);
        }
        VectorIterator& operator+=(difference_type n) {
            ptr = ptr + n;
            return (*this);
        }
        VectorIterator& operator-=(difference_type n) {
            ptr = ptr - n;
            return (*this);
        }
        difference_type operator-(VectorIterator j) {
            return (this->ptr - j.ptr);
        }
        bool operator<(const VectorIterator& rhs) {
            return (ptr < rhs.ptr);
        }
        bool operator>(const VectorIterator& rhs) {
            return (ptr > rhs.ptr);
        }
        bool operator<=(const VectorIterator& rhs) {
            return (ptr <= rhs.ptr);
        }
        bool operator>=(const VectorIterator& rhs) {
            return (ptr >= rhs.ptr);
        }
        value_type operator[] (difference_type n) {
            return (ptr[n]);
        }
    };
    
 
}

#endif
