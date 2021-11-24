#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

// reverse_iterator::base
// RandomIterator base() const;

namespace ft
{
    template <class RandomIterator>
    class reverse_iterator
    {
    public:
        typedef RandomIterator iterator_type;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::reference reference;
		typedef typename iterator_type::difference_type difference_type;
        operator reverse_iterator<const iterator_type>() const {
            std::cout << "/* ****** Implicit conversion for reverse ******* */" << std::endl;
			return (reverse_iterator<const iterator_type>(current)); 
		}
    protected:
        iterator_type current;
    public:
        reverse_iterator()  {} /**** default ***/
        explicit reverse_iterator (iterator_type it): current(it) {}  /**** initialisation ***/
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) { /**** copy ***/
            *this = rev_it;
        }
        // Returns a copy of the base iterator
        iterator_type base() const {
        	return (current);
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
            --current;
            return (*this);
        }
        reverse_iterator operator++(int) {
            reverse_iterator temp = *this;
            ++(*this);
            return (temp);
        }
        reverse_iterator& operator+= (difference_type n) {
            current -=n;
            return (*this);
        }
        reverse_iterator operator-(difference_type n) const {
            iterator_type it = base().operator+(n);
            reverse_iterator rev_itr(it);
            return (rev_itr);
        }
        reverse_iterator& operator--() {
            ++current;
            return (*this);
        }
        reverse_iterator operator--(int) {
            reverse_iterator temp = *this;
            --(*this);
            return (temp);
        }
        reverse_iterator& operator-= (difference_type n) {
            current +=n;
            return (*this);
        }
        // The iterator shall point to some object in order to be dereferenceable.
        pointer operator->() const {
            return &(operator*());
        }
        reference operator[] (difference_type n) const {
            return (*(base()-= ++n));
        }
        /*******************************************************************************************************************************/
        template <class It>
        friend reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n, const reverse_iterator<It>& rev_it) {
            reverse_iterator temp = rev_it;
            temp.current +=n;
            return (temp);
        }
        template <class It>
        friend typename reverse_iterator<It>::difference_type operator-(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) {
            return (rhs.base() - lhs.base());
        }
        template <class Iterator>
        friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return (lhs.base() == rhs.base());
        }
        template <class Iterator>
        friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return (!(lhs.base() == rhs.base()));
        }
        template <class Iterator>
        friend bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return (lhs.base() > rhs.base());
        }
        template <class Iterator>
        friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return (lhs.base() >= rhs.base());
        }
        template <class Iterator>
        friend bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return (lhs.base() < rhs.base());
        }
        template <class Iterator>
        friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
             return (lhs.base() <= rhs.base());
        }
        /*******************************************************************************************************************************/
    };
}

#endif
