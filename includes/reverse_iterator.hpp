#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

// reverse_iterator::base
// RandomIterator base() const;

namespace ft
{
    template <class RandomIterator>
    class reverse_iterator : public RandomIterator 
    {
    public:
        typedef RandomIterator iterator_type;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::reference reference;
		typedef typename iterator_type::difference_type difference_type;
        
        reverse_iterator()  {} /**** default ***/
        explicit reverse_iterator (iterator_type it): iterator_type(it) {} /**** initialisation ***/
        reverse_iterator (const reverse_iterator<RandomIterator>& rev_it) { /**** copy ***/
            *this = rev_it;
        }

        // The base iterator refers to the element that is next
        // to the element the reverse_iterator is currently pointing to
        // std::reverse_iterator(it).base() == it

        iterator_type base() const {
            iterator_type tmp(*this);
        	return (tmp);
        }
        // decreases a copy of its base iterator and returns the result of dereferencing it
        reference operator*() const {
        	    return (*(--base()));
        }
        reverse_iterator operator+(difference_type n) const {
            reverse_iterator tmp(*this);
            this->iterator_type::operator-(n);
            return (*this);
        }
        // the pre-increment decrements the base iterator (as if applying operator-- to it).
        reverse_iterator& operator++() {
            this->iterator_type::operator--();
            return (*this);
        }
        reverse_iterator operator++(int) {
            reverse_iterator temp = *this;
            ++(*this);
            return (temp);
        }
        // reverse_iterator& operator+= (difference_type n) {
        //     base().operator-=(n);
        //     return (*this);
        // }
        reverse_iterator operator- (difference_type n) const {
            reverse_iterator tmp(*this);
            tmp.iterator_type::operator+(n);
            return (tmp);
        }
        reverse_iterator& operator--() {

        }
        reverse_iterator  operator--(int) {

        }
        reverse_iterator& operator-= (difference_type n) {

        }
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
