#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "iterator.hpp"
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
		typedef ft::Iterator<T> iterator;
		typedef ft::ConstIterator<T> const_iterator;
	private:
		size_type	_size;
		size_type	_capacity;
		pointer		_array;
		allocator_type _allocator;
	public:
	/******************** Member functions *********************/	
	// without explicit keyword
	vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0){
        std::cout << "here is the constructor for the vector" << std::endl;
		_allocator = alloc;
		_array = _allocator.allocate(_capacity);
	}
	vector (size_type n, const value_type& val = value_type(),
	             const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n) {
			unsigned long i = 0;
			_allocator = alloc;
			_array = _allocator.allocate(_capacity);
			while (i < _size)
			{
				_array[i] = val;
				i++;
			}
	}
	// template <class InputIterator>
	// vector (InputIterator first, InputIterator last,
	//              const allocator_type& alloc = allocator_type()) {

	// }
	vector (const vector& x) {
       	std::cout << "here is the copy" << std::endl;
		*this = x;
	}
	~vector() {
		_allocator.deallocate(_array, _capacity);
		cout << "free memory\n";
	}
	vector& operator= (const vector& x) {
        std::cout << "here is the assignation" << std::endl;
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
	const_iterator begin() const {
		return (const_iterator(_array));
	}
	iterator end() {
		return (iterator(_array + _size));
	}
	const_iterator end() const {
		return (const_iterator(_array + _size));
	}
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

	/******************** Capacity *********************/	
	size_type size() const {
		return (_size);
	}
	size_type max_size() const {
		return (4611686018427387903);
	}
	void resize (size_type n, value_type val = value_type());
	size_type capacity() const {
		return (_capacity);
	}
	bool empty() const {
		return (_size == 0);
	}
	void reserve (size_type n);
	
	/******************** Element access *********************/	
	// reference operator[] (size_type n);
	// const_reference operator[] (size_type n) const;
	// reference at (size_type n);
	// const_reference at (size_type n) const;
	// reference front();
	// const_reference front() const;
	// reference back();
	// const_reference back() const;

	/******************** Modifiers *********************/	
	// template <class InputIterator>
	// void assign (InputIterator first, InputIterator last);
	// void assign (size_type n, const value_type& val);
	// void push_back (const value_type& val);
	// void pop_back();
	// iterator insert (iterator position, const value_type& val);
	// void insert (iterator position, size_type n, const value_type& val);
	// template <class InputIterator>
	// void insert (iterator position, InputIterator first, InputIterator last);
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
	friend ostream & operator<<(ostream & o, vector const & rhs);
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
	ostream & operator<<(ostream & o, vector<int> const & rhs) {
	unsigned long i = 0;

	cout << "\e[1;35m/*******Vector Details: *******/\e[1;37m" << endl;
	cout << "size: " << rhs._size << '\n';
	cout << "capacity: " << rhs._capacity << '\n';
	cout << "is_empty: " << boolalpha << rhs.empty() << '\n';
	while (i < rhs._size)
	{
		o << rhs._array[i] << " ";
		i++;
	}
	cout << '\n';
	cout << "\e[1;35m/******* End Details *******/\e[1;37m" << endl;
	return o;
	}
}
#endif