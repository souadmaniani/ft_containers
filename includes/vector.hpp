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
		vector() : _size(0), _capacity(7)
		{
			_array = new int[_capacity];
		}
		vector (int n, const int val): _size(n), _capacity(7) {
			int i = -1;
			_array = new int[_capacity];
			while (++i < n)
				_array[i] = val;
		}
		vector (const vector& x) {
			
		}
		~vector() {
			delete [] _array;
		}
		void push_back (const int val) {
			_array[_size] = val;
			_size++;
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
		// reference operator[] (int n) {

		// }
		friend bool operator== (const vector& lhs, const vector& rhs);
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

	ostream & operator<<(ostream & o, vector const & rhs) {
		int i = -1;

		cout << "size: " << rhs._size << '\n';
		cout << "capacity: " << rhs._capacity << '\n';
		cout << "is_empty: " << rhs.empty() << '\n';
		while (++i < rhs._size)
			o << rhs._array[i] << " ";
		while (i < rhs._capacity)
			o << rhs._array[i++] << " ";
		cout << '\n';
		return o;
	}
}

#endif