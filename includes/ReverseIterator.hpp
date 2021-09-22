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
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::reference reference;
		typedef typename iterator_type::difference_type difference_type;

        // operator ReverseIterator<const RandomIterator>() const {
		// 	return (ReverseIterator<const RandomIterator>(this->ptr)); 
		// }

        ReverseIterator()  {
            return (base());
        }
        explicit ReverseIterator (iterator_type it): iterator_type(it) {
        }
        ReverseIterator (const ReverseIterator<RandomIterator>& rev_it) {
            *this = rev_it;
        }
        iterator_type base() const {
            return (*this);
        }
        reference operator*() const {
            return ((base()).operator*());
        }
        // reverse_iterator operator+ (difference_type n) const;
        // reverse_iterator& operator++();
        // reverse_iterator  operator++(int);
        // reverse_iterator& operator+= (difference_type n);
        // reverse_iterator operator- (difference_type n) const;
        // reverse_iterator& operator--();
        // reverse_iterator  operator--(int);
        // reverse_iterator& operator-= (difference_type n);
        // pointer operator->() const;
        // reference operator[] (difference_type n) const;
        
        // template <class Iterator>
        // bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        // template <class Iterator>
        // bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

        // template <class Iterator>
        // typename reverse_iterator<Iterator>::difference_type operator- (
        //     const reverse_iterator<Iterator>& lhs,
        //     const reverse_iterator<Iterator>& rhs);
        // template <class Iterator>
        // reverse_iterator<Iterator> operator+ (
        //     typename reverse_iterator<Iterator>::difference_type n,
        //     const reverse_iterator<Iterator>& rev_it);
    };
}

#endif
