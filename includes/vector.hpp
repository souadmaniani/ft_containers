#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "vectorIterator.hpp"
#include "reverse_iterator.hpp"
#include "../utils/utils.hpp"
// !!capacity bhal dyal std::vector
namespace ft
{
	template <class T, class Alloc = std::allocator<T> > 
	class vector;
	template <class T>
	std::ostream & operator<< (std::ostream & o, const vector<T>& rhs);
	template <class T, class Alloc> 

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
		typedef ft::VectorIterator<T> iterator;
		typedef ft::VectorIterator<const T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const iterator> const_reverse_iterator;

	private:
		size_type	_size;
		size_type	_capacity;
		pointer		_array;
		allocator_type _allocator;
		pointer array_copy(pointer dest, pointer src, unsigned long size) {
			unsigned long i = 0;
			while (i < size)
			{
				dest[i] = src[i];
				i++;
			}
			return (dest);
		}
		void print_array(pointer arr, unsigned long n) {
			for (size_t i = 0; i < n; i++)
			{
				std::cout << arr[i] << std::endl;
			}
		}
	public:
	/******************** Member functions *********************/
	// WITHOUT EXPLICIT
	vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0){
		_allocator = alloc;
		_array = _allocator.allocate(_capacity);
	}
	
	explicit vector (size_type n, const value_type& val = value_type(),
	             const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n) {
			unsigned long i;
			i = 0;
			_allocator = alloc;
			_array = _allocator.allocate(_size);
			while (i < n)
			{
				_array[i] = val;
				i++;
			}
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
				// enable_if first and last are type InputIterator
				_allocator = alloc;
				_size = last - first;
				_capacity = last - first;
				_array = _allocator.allocate(_size);
				unsigned long i = 0;
				while (first != last)
				{
					_array[i++] = *first;
					first++;
				}
	}

	vector (const vector& x) {
		*this = x;
	}

	~vector() {
		_allocator.deallocate(_array, _capacity);
	}

	vector& operator= (const vector& x) {
		unsigned long i;

		i = 0;
		if (_size < x._size)
		{
			_capacity = x._capacity;
			_allocator.deallocate(_array, _capacity);
			_array = _allocator.allocate(_capacity);
		}
		while (i < x._size)
		{
			_array[i] = x._array[i];
			i++;
		}
		_size = x._size;
		return (*this);
	}
	/******************** iterators *********************/	
	iterator begin() {
		return (iterator(_array));
	}
	// no viable conversion from 'Iterator<int>' to 'Iterator<const int>'
	const_iterator begin() const {
		return (const_iterator(_array));
	}
	iterator end() {
		return (iterator(_array + _size));
	}
	const_iterator end() const {
		return (const_iterator(_array + _size));
	}
	/***** Reverse Iterator***/
	reverse_iterator rbegin() {
		return (reverse_iterator(end()));
	}
	const_reverse_iterator rbegin() const {
		return (const_reverse_iterator(end()));
	}
	reverse_iterator rend() {
		return (reverse_iterator(begin()));
	}
	const_reverse_iterator rend() const {
		return (const_reverse_iterator(begin()));
	}

	/******************** Capacity *********************/	
	size_type size() const {
		return (_size);
	}
	size_type max_size() const {
		return (4611686018427387903);
	}
	void resize (size_type n, value_type val = value_type()) {
		pointer temp;
		unsigned long i = 0;
		if (n > _size)
		{
			if (n > _capacity) {
				temp = _allocator.allocate(n);
				temp = array_copy(temp, _array, n);
				_allocator.deallocate(_array, _capacity);
				_capacity = _size * 2;
				_array = _allocator.allocate(_capacity);
				_array = array_copy(_array, temp, n);
				_allocator.deallocate(temp, n);
			}
			while(i < n - _size) {
				_array[_size + i] = val;
				i++;
			}
		}
		_size = n;
	}
	size_type capacity() const {
		return (_capacity);
	}
	bool empty() const {
		return (_size == 0);
	}
	void reserve (size_type n) {
		pointer temp;
		if (n > _capacity) {
			temp = _allocator.allocate(n);
			temp = array_copy(temp, _array, _size);
			_allocator.deallocate(_array, _capacity);
			_array = temp;
			_capacity = n;
		}
	}
	
	/******************** Element access *********************/	
	reference operator[] (size_type n) {
		return (_array[n]);
	}
	const_reference operator[] (size_type n) const {
		return (_array[n]);
	}
	reference at (size_type n) {
		if (!(n < _size))
			throw std::out_of_range("vector");
		return (_array[n]);
	}
	const_reference at (size_type n) const {
		if (!(n < _size))
			throw std::out_of_range("vector");
		return (_array[n]);
	}
	reference front() {
		return (*begin());
	}
	const_reference front() const {
		return (*begin());
	}
	reference back() {
		return (_array[_size - 1]);
	}
	const_reference back() const {
		return (_array[_size - 1]);
	}

	/******************** Modifiers *********************/	
	void assign (size_type n, const value_type& val) {
		unsigned long i = 0;

		if (n > _capacity) {
			_allocator.deallocate(_array, _capacity);
			_capacity = n;
			_array = _allocator.allocate(_capacity);
		}
		while(i < n) {
			_array[i] = val;
			i++;
		}
		_size = n;
	}
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
					typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
		unsigned long i = 0;

		if (last - first > _capacity) {
			_allocator.deallocate(_array, _capacity);
			_capacity = last - first;
			_array = _allocator.allocate(_capacity);
		}
		_size = last - first;
		while (first != last)
		{
			_array[i++] = *first;
			first++;
		}
	}
	void push_back (const value_type& val) {
		pointer temp;

		if (_size == _capacity) {
			temp = _allocator.allocate(_size * 2);
			temp = array_copy(temp, _array, _size);
			_allocator.deallocate(_array, _capacity);
			_capacity = _size * 2;
			_array = temp;
		}
		_array[_size] = val;
		_size++;
	}
	void pop_back() {
		_size--;
	}
	iterator insert (iterator position, const value_type& val) { /* single element */
		pointer temp;

		long long index = get_index(iterator &position);
		unsigned long i = 0;
		if (_size == _capacity) {
			_capacity = _size * 2;
			temp = _allocator.allocate(_capacity);
			temp = array_copy(temp, _array, _size);
			_allocator.deallocate(_array, _capacity);
			_array = temp;
		}
		// i = _size;
		// while (i-- > index)
		// 	_array[i + 1] = _array[i];
		// _array[index] = val;

		pointer ptr = _array + _size;
		
		while(&(*ptr) > &(*position)) {
			*(_array + 1) = *_array;
			ptr--;
		}
		return (position);
	}
	// void insert (iterator position, size_type n, const value_type& val) { /* fill */

	// }
	// template <class InputIterator>
	// void insert (iterator position, InputIterator first, InputIterator last) { /* range */

	// }
	// iterator erase (iterator position);
	// iterator erase (iterator first, iterator last);
	// void swap (vector& x);
	// void clear();

	// allocator_type get_allocator() const;

	/******************** relational operators *********************/	
	// friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	friend std::ostream & operator<< <>(std::ostream & o, const vector& rhs);
	};
	// template <class T, class Alloc>
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	template <class T>
	std::ostream & operator<<(std::ostream & o,const vector<T>& rhs) {
		unsigned long i = 0;

		std::cout << "\e[1;35m/*******Vector Details: *******/\e[1;37m" << "\n";
		std::cout << "size: " << rhs._size << '\n';
		std::cout << "capacity: " << rhs._capacity << '\n';
		std::cout << "is_empty: " << std::boolalpha << rhs.empty() << '\n';
		while (i < rhs._size)
		{
			o << rhs._array[i] << " ";
			i++;
		}
		std::cout << '\n';
		std::cout << "\e[1;35m/******* End Details *******/\e[1;37m" << "\n";
		return o;
	}
}
#endif