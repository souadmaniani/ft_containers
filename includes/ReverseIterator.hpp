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

        ReverseIterator()  {}
        explicit ReverseIterator (iterator_type it): iterator_type(it) { }
        // ReverseIterator (const ReverseIterator<RandomIterator>& rev_it) {
        //     *this = rev_it;
        // }
        iterator_type base() const {
            return (*this);
        }
        reference operator*() const {
            return ((base()).operator*());
        }
        ReverseIterator operator+ (difference_type n) const {
            std::cout << "operator+" << std::endl;
            ReverseIterator t(*this);
            t.ptr -= n;
            return (t);
        }
        // the pre-increment decrements the base iterator (as if applying operator-- to it).
        ReverseIterator& operator++() {
            // return base().operator--()); or // MA3JBTNICH HADI
            std::cout << "operator++()" << std::endl;
            --this->ptr;
            return (*this);
        }
        ReverseIterator  operator++(int) {
            ReverseIterator temp = *this;
            ++(*this);
            return (temp);
        }
        ReverseIterator& operator+= (difference_type n) {
            base().operator-=(n);
            return (*this);
        }
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
