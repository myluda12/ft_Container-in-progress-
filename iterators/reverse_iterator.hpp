#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::value_type      value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer         pointer;
            typedef typename iterator_traits<Iterator>::reference       reference;
            typedef typename iterator_traits<Iterator>::iterator_category  iterator_category;

            // Constructors
            reverse_iterator() : _pointer(nullptr) {};
            explicit reverse_iterator (iterator_type it) : _pointer(--it) {};
            template <typename Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) 
            {
                this->_pointer = --rev_it.base();
            }

            iterator_type base() const 
            {
                iterator_type tmp(_pointer);
                return ++tmp;
            }
            operator reverse_iterator<const iterator_type>() const 
            {
                return reverse_iterator<const iterator_type>(this->_pointer);
            } 

            reference operator*() const
            {
                Iterator tmp (_pointer);
                return *tmp; 
            }

            reverse_iterator operator+ (difference_type n) const
            {
                reverse_iterator tmp(*this);
                tmp._pointer =  tmp._pointer - n;

                return tmp;
            }
            pointer operator->()const
            {
                return &(operator*());
            }
            reverse_iterator& operator++()
            {
                --_pointer;
                return *this;
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp(*this);
                --_pointer;
                return tmp;
            }
            reverse_iterator& operator--()
            {
                this->_pointer++;
                return *this;
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp(*this);
                ++_pointer;
                return tmp;
            }
            reverse_iterator& operator+=(difference_type n)
            {
                _pointer = _pointer - n;
                return *this;
            }
            reverse_iterator  operator- (difference_type n) const
            {
                reverse_iterator tmp(this->base());
                tmp._pointer += n;
                return tmp;
            }
            reverse_iterator& operator-=(difference_type n)
            {
                _pointer +=  n;
                return *this;
            }
            	reference	operator[](difference_type n) const{return _pointer[-n];};
            private :
                iterator_type _pointer;
          


    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return x.base() == y.base();
    };
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return x.base() > y.base();
    };
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return x.base() != y.base();
    };
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return x.base() < y.base();
    };
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return x.base() <= y.base();
    };
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return x.base() >= y.base();
    };
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {
        return y.base() - x.base();
    };
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& x)
    {
        return reverse_iterator<Iterator>(x.base() - n);
    };
   
}

//it = rv2 + 5;