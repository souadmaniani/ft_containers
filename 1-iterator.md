# iterator:
    template<
        class Category,
        class T,
        class Distance = std::ptrdiff_t,
        class Pointer = T*,
        class Reference = T&
     > struct iterator;
- std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
- When working with the C++ container library, the proper type for the difference between iterators is the member typedef difference_type, which is often synonymous with std::ptrdiff_t.
### Category 
- Input Iterator (Read only, forward moving)
- Output Iterator (Write only, forward moving)
- Forward Iterator (Read and Write, forward moving)
- Biderctional Iterator (Read and Write, moves forward or backward)
- Random Access Iterator (Read and Write, random access)
# iterator_traits
    template <class Iterator> class iterator_traits;
    template <class T> class iterator_traits<T*>;
    template <class T> class iterator_traits<const T*>;
- Traits class defining properties of iterators.
- [iterator_traits] (https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)
# reverse_iterator
    template< class Iter > class reverse_iterator;
#### Usefull links
- [Random Access Iterator] (https://www.boost.org/sgi/stl/RandomAccessIterator.html)
- https://www.geeksforgeeks.org/const-vs-regular-iterators-in-c-with-examples/
- https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
- https://stackoverflow.com/questions/2844339/c-iterator-and-const-iterator-problem-for-own-container-class
- https://www.drdobbs.com/the-standard-librarian-defining-iterato/184401331
- https://en.cppreference.com/w/cpp/language/cast_operator