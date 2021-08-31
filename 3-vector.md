# Vector
    template <class T, class Allocator = std::allocator<T> > class vector;
- Vectors are sequence containers representing arrays that can change in size.

### Member types
- value_type (The first template parameter (T))
- allocator_type (The second template parameter (Alloc)); defaults to: allocator<value_type>
- reference (allocator_type::reference); allocator: value_type&
- const_reference (allocator_type::const_reference); allocator: const value_type&
- pointer (allocator_type::pointer); allocator: value_type*
- const_pointer (allocator_type::const_pointer); allocator: const value_type*
- iterator (a random access iterator to value_type)
- const_iterator (a random access iterator to const value_type)
- reverse_iterator (reverse_iterator<iterator>)
- const_reverse_iterator (reverse_iterator<const_iterator>)
- difference_type (a signed integral type, identical to: iterator_traits<iterator>::difference_type)
- size_type (represent any non-negative value of difference_type); usually the same as size_t

### Member functions
#### (constructor)
	(default) explicit vector (const allocator_type& alloc = allocator_type());
	(fill) explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
	(range) template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
	(copy) vector (const vector& x);
	
#### (destructor)
	~vector();
#### operator=
	vector& operator= (const vector& x);
### Iterators:
#### begin
	iterator begin();
	const_iterator begin() const;
#### end
	iterator end();
	const_iterator end() const;
#### rbegin
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
#### rend
	reverse_iterator rend();
	const_reverse_iterator rend() const;
### Capacity:
#### size
	size_type size() const;
#### max_size
	size_type max_size() const;
#### resize
	void resize (size_type n, value_type val = value_type());
- Resizes the container so that it contains n elements.
#### capacity 
	size_type capacity() const;
- Return size of allocated storage capacity
#### empty
	bool empty() const;
- Returns whether the vector is empty (i.e. whether its size is 0).
#### reserve
	void reserve (size_type n);
- Request a change in capacity

### Element access:
#### operator[]
	reference operator[] (size_type n);
	const_reference operator[] (size_type n) const;
#### at
	reference at (size_type n);
	const_reference at (size_type n) const;
#### front
	reference front();
	const_reference front() const;
- Access first element
#### back
	reference back();
	const_reference back() const;
- Access last element

### Modifiers:
#### assign
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);
- Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
#### push_back
	void push_back (const value_type& val);
#### pop_back
	void pop_back();
#### insert
	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);
#### erase
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);
#### swap
	void swap (vector& x);
#### clear
	void clear();
- Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.

### Allocator:
#### get_allocator
	allocator_type get_allocator() const;
- Returns a copy of the allocator object associated with the vector.

### Non-member function overloads
#### relational operators
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
#### swap
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
