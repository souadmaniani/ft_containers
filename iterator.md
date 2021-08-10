# iterator:
    template<
    class Category,
    class T,
    class Distance = std::ptrdiff_t,
    class Pointer = T*,
    class Reference = T&
     > struct iterator;
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
. [iterator_traits] (https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)

