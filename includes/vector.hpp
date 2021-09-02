#ifndef VECTOR_HPP
#define VECTOR_HPP
using namespace std;

namespace ft
{
    template <class T, class Alloc = std::allocator<T> > 
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T* pointer;
        typedef const T* const_pointer;
		typedef unsigned long size_type;
    private:
		size_type	_size;
		size_type	_capacity;
		T*          _array;
    public:
	// without explicit keyword
	vector (const allocator_type& alloc = allocator_type()) : _size(0) _capacity(1){
		_array = alloc.allocate(_capacity);
	}
	vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
	template <class InputIterator>
    vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
	vector (const vector& x);
    vector::~vector() {}

	};
}
#endif