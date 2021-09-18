#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

// reverse_iterator::base
// RandomIterator base() const;

namespace ft
{
    template <class RandomIterator>
    class ReverseIterator : public RandomIterator 
    {
    public:
        typedef RandomIterator iterator_type;

        ReverseIterator()  {}
        explicit ReverseIterator (iterator_type it):  RandomIterator(it) {
            // RandomIterator(it);
        }
        ReverseIterator (const ReverseIterator<RandomIterator>& rev_it) {
            *this = rev_it;
        }
    };
}

#endif
