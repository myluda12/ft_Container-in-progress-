#pragma once
#include <iostream>

#include "iterator_traits.hpp"

namespace ft
{
    template< class T >
    class random_access_iterator
    {
        public :
            typedef typename std::iterator<std::random_access_iterator_tag, T>::value_type value_type;
            typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;



            random_access_iterator() : _pointer(nullptr) {};
            random_access_iterator(T* ptr) : _pointer(ptr) {};
            random_access_iterator(const random_access_iterator& other) : _pointer(other.get_pointer()) {};
            ~random_access_iterator() {};

            random_access_iterator& operator=(const random_access_iterator& other)
            {
                _pointer = other.get_pointer();
                return *this;
            }

            random_access_iterator& operator++()
            {
                ++_pointer;
                return *this;
            }
            random_access_iterator operator++(int)
            {
                random_access_iterator prev(_pointer);
                _pointer++;
                return prev;
            }

            random_access_iterator& operator--()
            {
                --_pointer;
                return *this;
            }

            random_access_iterator operator--(int)
            {
                random_access_iterator prev(_pointer);
                _pointer--;
                return prev;
            }
            random_access_iterator& operator+=(difference_type n)
            {
                _pointer += n;
                return *this;
            }
            random_access_iterator& operator-=(difference_type n)
            {
                _pointer -= n;
                return *this;
            }
            random_access_iterator operator+(difference_type n)
            {
                random_access_iterator temp = *this;
                temp._pointer += n;
                return temp;
            }
            // 1 5 3 2 1 0
            random_access_iterator operator-(difference_type n)
            {
                random_access_iterator temp(_pointer);
                temp._pointer -=  n;
                return temp;
            }
            difference_type operator-(const random_access_iterator& other)
            {
                return _pointer - other.get_pointer();
            }
            reference operator[](difference_type n) const
            {
                return *(_pointer + n);
            }
            reference operator*() const
            {
                return *_pointer;
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            operator	random_access_iterator<const value_type>() const
            {
				return random_access_iterator<const value_type>(_pointer);
			}

            pointer get_pointer() const
            {
                return this->_pointer;
            }

            // bool operator==(const random_access_iterator& other)
            // {
            //     return _pointer == other._pointer;
            // }
        // template<class U>
        // bool operator==(const random_access_iterator<U>& rhs) 
        // {
        //     return  (const)this->_pointer == rhs.get_pointer();
        // }
        // template<class U>
        // bool operator!=(const random_access_iterator<U>& rhs) 
        // {
        //     return this->_pointer != rhs.get_pointer();
        // }
        // template<class U>
        // bool operator<(const random_access_iterator<U>& rhs) 
        // {
        //     return this->_pointer < rhs.get_pointer();
        // }
        // template<class U>
        // bool operator>(const random_access_iterator<U>& rhs) 
        // {
        //     return this->_pointer > rhs.get_pointer();
        // }
        // template<class U>
        // bool operator<=(const random_access_iterator<U>& rhs) 
        // {
        //     return this->_pointer <= rhs.get_pointer();
        // }
        // template<class U>
        // bool operator>=(const random_access_iterator<U>& rhs) 
        // {
        //     return this->_pointer >= rhs.get_pointer();
        // }

        
        protected :
            pointer _pointer;

        

    };
    
        template <class T>
        bool    operator==(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() == it2.get_pointer());
        };
        template <class T>
        bool    operator!=(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() != it2.get_pointer());
        };
        template <class T>
        bool    operator<(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() < it2.get_pointer());
        };
        template <class T>
        bool    operator>(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() > it2.get_pointer());
        };
        template <class T>
        bool    operator<=(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() <= it2.get_pointer());
        };
        template <class T>
        bool    operator>=(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() >= it2.get_pointer());
        };
        template <class T>
        typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() - it2.get_pointer());
        };
        template <class T>
        typename random_access_iterator<T>::difference_type operator+(const random_access_iterator<T> &it1, const random_access_iterator<T> &it2)
        {
        return (it1.get_pointer() + it2.get_pointer());
        };
        template <class T>
        random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it)
        {
        return (it.get_pointer() + n);
        };

}


/*

    random_access_iterator& operator--()
    {}
    random_access_iterator& operator++(int)
    {}

    B &a = B(10);
    j= 6
    int i = j++; i = 6; j = 7

    class a;
    class b;
    int *i;
    *i 
    *i
    i->

    a = b++;
 DIIBB
operto++

    A -> C
    |
    X -> T
        | 
        P
*/