#ifndef VECTOR_HPP
#define VECTOR_HPP

using namespace std;

namespace ft {
	class vector
	{
	private:
		int *_array;
		int _capacity;
		int _size;
	public:
		vector() : _size(0), _capacity(7) {
			_array = new int[_capacity];
		}
		vector (int n, const int val = 0): _size(n), _capacity(7) {
			int i = -1;
			_array = new int[_capacity];
			while (++i < n)
				_array[i] = val;
		}
		vector (const vector& x) {
			int i;

			i = -1;
			_capacity = x._capacity;
			_size = x._size;
			_array = new int[_capacity];
			while (++i < _size)
				_array[i] = x._array[i];
		}
		vector& operator= (const vector& x) {
			int i;

			i = -1;
			if (_size < x._size)
			{
				_capacity = x._capacity;
				delete [] _array;
				_array = new int[_capacity];
			}
			while (++i < x._size)
				_array[i] = x._array[i];
			_size = x._size;
			return (*this);
		}
		~vector() {
			delete [] _array;
			std::cout << "vector deleted" << std::endl;
		}
		void push_back (const int val) {
			int * arr;
			int i;

			i = -1;
			if (_capacity <= _size)
			{
				_capacity = _size + 5;
				arr = new int[_capacity];
				while (++i < _size)
					arr[i] = _array[i];
				arr[i] = val;
				delete [] _array;
				_array = arr;
			}
			else
				_array[_size] = val;
			_size++;
		}
		void pop_back() {
			_size--;
		}
		int size() const {
			return _size;
		}
		int capacity() const {
			return _capacity;
		}
		bool empty() const {
			return _size == 0;
		}
		int& operator[] (int n) {
				return _array[n];
		}
		int& at (int n) {
			if (n >=_size || n < 0)
				throw out_of_range("Index out of range");
			return _array[n];
		}
		int& front () {
			return (_array[0]);
		}
		int& back () {
			return (_array[_size - 1]);
		}
		void insert (int n, const int& val);
		void erase (int position) {
			int i;
			if (position < _size  && position >= 0)
			{
				i = position - 1;
				while (++i < _size)
					_array[i] = _array[i + 1];
			}
			_size--;
		}
		void clear() {
			// update
			_size = 0;
		}
		friend bool operator== (const vector& lhs, const vector& rhs);
		friend bool operator!= (const vector& lhs, const vector& rhs);
		friend ostream & operator<<(ostream & o, vector const & rhs);
	};

	bool operator== (const vector& lhs, const vector& rhs) {
	    if (lhs.size() != rhs.size())
	        return false;
	    int i = -1;
	    while (++i < lhs._size)
	    {
	        if (lhs._array[i] != rhs._array[i])
	            return false;
	    }
	    return true;
	}
	bool operator!= (const vector& lhs, const vector& rhs) {
		return (!(lhs == rhs));
	}
	ostream & operator<<(ostream & o, vector const & rhs) {
		int i = -1;

		std::cout << "\e[1;35m/*******Vector Details: *******/\e[1;37m" << std::endl;
		cout << "size: " << rhs._size << '\n';
		cout << "capacity: " << rhs._capacity << '\n';
		cout << "is_empty: " << boolalpha << rhs.empty() << '\n';
		while (++i < rhs._size)
			o << rhs._array[i] << " ";
		while (i < rhs._capacity)
			o << rhs._array[i++] << " ";
		cout << '\n';
		std::cout << "\e[1;35m/******* End Details *******/\e[1;37m" << std::endl;
		return o;
	}
}

#endif