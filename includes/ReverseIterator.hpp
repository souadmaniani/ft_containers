#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

// ReverseIterator::base
// RandomIterator base() const;

namespace ft
{
    template <class RandomIterator>
    class ReverseIterator : public RandomIterator 
    {
    public:
        typedef RandomIterator iterator_type;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::reference reference;
		typedef typename iterator_type::difference_type difference_type;

        // operator ReverseIterator<const RandomIterator>() const {
		// 	return (ReverseIterator<const RandomIterator>(this->ptr)); 
		// }

        ReverseIterator()  {} /**** default ***/
        explicit ReverseIterator (iterator_type it): iterator_type(it) { } /**** initialisation ***/
        ReverseIterator (const ReverseIterator<RandomIterator>& rev_it) { /**** copy ***/
            *this = rev_it;
        }

        // The base iterator refers to the element that is next
        // to the element the reverse_iterator is currently pointing to
        // std::reverse_iterator(it).base() == it
        iterator_type base() const {
            return (*(this - 1));
        }
        // decreases a copy of its base iterator and returns the result of dereferencing it
        reference operator*() const {
            return ((base() - 1).operator*() );
        }
        ReverseIterator operator+ (difference_type n) const {
            std::cout << "operator+" << std::endl;
            ReverseIterator t(*this);
            t.ptr -= n;
            return (t);
        }
        // the pre-increment decrements the base iterator (as if applying operator-- to it).
        ReverseIterator& operator++() {
            std::cout << "operator++()" << std::endl;
            base().operator--();
            std::cout << (base() - 3).operator*() << "\n";
            return (*this);
        }
        // ReverseIterator  operator++(int) {
        //     ReverseIterator temp = *this;
        //     ++(*this);
        //     return (temp);
        // }
        // ReverseIterator& operator+= (difference_type n) {
        //     base().operator-=(n);
        //     return (*this);
        // }
        // ReverseIterator operator- (difference_type n) const;
        // ReverseIterator& operator--();
        // ReverseIterator  operator--(int);
        // ReverseIterator& operator-= (difference_type n);
        // pointer operator->() const;
        // reference operator[] (difference_type n) const;
        
        // template <class Iterator>
        // bool operator== (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator!= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator<  (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator<= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator>  (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator>= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs);

        // template <class Iterator>
        // typename ReverseIterator<Iterator>::difference_type operator- (
        //     const ReverseIterator<Iterator>& lhs,
        //     const ReverseIterator<Iterator>& rhs);
        // template <class Iterator>
        // ReverseIterator<Iterator> operator+ (
        //     typename ReverseIterator<Iterator>::difference_type n,
        //     const ReverseIterator<Iterator>& rev_it);
    };
}

#endif
