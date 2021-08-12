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
- [iterator_traits] (https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)
# reverse_iterator
    template< class Iter > class reverse_iterator;
# enable_if
    template <bool Cond, class T = void> struct enable_if;
- SFINAE: Substitution Failure is not an Error, means that if the compiler fails to specialize a template with a given template argument list, it does not issue an error. It does when it cannot find any suitable function/class to be called/instantiated (either due to a lack of suitably declared functions/classes or an error during instantiation).
- [SFINAE] (https://www.thewolfsound.com/sfinae-substitution-failure-is-not-an-error/)

