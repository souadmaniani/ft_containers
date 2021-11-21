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
        // The base iterator is an iterator of the same type as the one used
        // to construct the reverse_iterator
        // Returns a copy of the base iterator
        iterator_type base() const {
        	return (*this);
        }
        // decreases a copy of its base iterator and returns the result of dereferencing it
        reference operator*() const {
        	    return (*(--base()));
        }
        reverse_iterator operator+(difference_type n) const {
            iterator_type it = base().operator-(n);
            reverse_iterator rev_itr(it);
            return (rev_itr);
        }
        // the pre-increment decrements the base iterator (as if applying operator-- to it).
        reverse_iterator& operator++() {
            iterator_type::operator--();
            return (*this);
        }
        reverse_iterator operator++(int) {
            reverse_iterator temp = *this;
            ++(*this);
            return (temp);
        }
        reverse_iterator& operator+= (difference_type n) {
            iterator_type::operator-=(n);
            return (*this);
        }
        reverse_iterator operator-(difference_type n) const {
            iterator_type it = this->base().operator+(n);
            reverse_iterator rev_itr(it);
            return (rev_itr);
        }
        reverse_iterator& operator--() {
            iterator_type::operator++();
            return (*this);
        }
        reverse_iterator operator--(int) {
            reverse_iterator temp = *this;
            --(*this);
            return (temp);
        }
        reverse_iterator& operator-= (difference_type n) {
            iterator_type::operator+=(n);
            return (*this);
        }
        // The iterator shall point to some object in order to be dereferenceable.
        pointer operator->() const {
            return &(operator*());
        }
        reference operator[] (difference_type n) const {
            return (*(base()-= ++n));
        }
        template <class Iterator>
        friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return (1 == 1);
        }
        template <class Iterator>
        friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        template <class Iterator>
        friend bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        template <class Iterator>
        friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        template <class Iterator>
        friend bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        template <class Iterator>
        friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

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
