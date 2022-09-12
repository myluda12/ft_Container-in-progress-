// constructing vectors
#pragma once

#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
#include <memory>


namespace ft
{
    template <class T, class Alloc = std::allocator<T> > 
    class vector 
    {
      public :
            typedef Alloc                                     allocator_type;
            typedef T                                         value_type; 
            typedef typename allocator_type::reference        reference;
            typedef typename allocator_type::const_reference  const_reference;
            typedef size_t                                    size_type;
            typedef typename allocator_type::pointer          pointer;
            typedef typename allocator_type::const_pointer    const_pointer;
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                        reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                  const_reverse_iterator;
            typedef size_t                                            size_t;
            //typedef std::reverse_iterator<iterator>         reverse_iterator;
            //typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

            explicit vector ()
              {
                _size = 0;
                _capacity = 0;
                _alloc = allocator_type();
                _buff = NULL;
              }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
              
              {
                this->_alloc = alloc;
                this->_buff = this->_alloc.allocate(n);
                for (size_type i = 0 ; i < n ; i++)
                  this->_alloc.construct(&this->_buff[i], val);
                  _size = n;
                  _capacity = n;
              }



              // template <class InputIterator>
              // vector (InputIterator first, InputIterator last, const allocator_type& _alloc = allocator_type()) : _alloc(_alloc)
              			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()): _alloc(alloc)
              {
                size_t n = last - first;
                _buff = _alloc.allocate(n);
                for (size_t i = 0 ; i < n ; i++)
                  _alloc.construct(&_buff[i], first[i]);
                  _size = n;
                  _capacity = n;
              }
              
               




            // construct/copy/destroy:
            // explicit vector(const Allocator& = Allocator());
            // explicit vector(size_type n, const bool& value = bool(), const Allocator& = Allocator());
            
            
            vector (const vector& x)
            {
              _size = x._size;
              _capacity = x._capacity;
              _buff = _alloc.allocate(_capacity);
              for (size_t i = 0 ; i < _size ; i++)
                _alloc.construct(&_buff[i], x._buff[i]);
            }
            
            ~vector()
            {
              for (size_t i = 0 ; i < _size ; i++)
                _alloc.destroy(&_buff[i]);
              if (_capacity != 0)
               _alloc.deallocate(_buff, _capacity);
            }

            vector<value_type,std::allocator<T> >& operator=(const vector<value_type,std::allocator<T> >& x)
            {
              if (this != &x)
              {
                _size = x._size;
                _capacity = x._capacity;
                _buff = _alloc.allocate(_capacity);
                for (size_t i = 0 ; i < _size ; i++)
                  _alloc.construct(&_buff[i], x._buff[i]);
              }
              return *this;
            }

            template <class InputIterator>
            void assign(InputIterator first, InputIterator last)
            {
              size_t n = last - first;
              if (n > _capacity)
              {
                for (size_t i = 0 ; i < _size ; i++)
                  _alloc.destroy(&_buff[i]);
                if (!_buff)
                  _alloc.deallocate(_buff, _capacity);
                _buff = _alloc.allocate(n);
                _capacity = n;
              }
              for (size_t i = 0 ; i < n ; i++)
                _alloc.construct(&_buff[i], first[i]);
              _size = n;
            }

            void assign(size_type n, const T& val)
            {
                for(size_t i = 0 ; i < _size ; i++)
                  _alloc.destroy(&_buff[i]);
                _size = n;
                if (n > _capacity)
                {
                  if (!_buff)
                    _alloc.deallocate(_buff, _capacity);
                  _capacity = n;
                  _buff = _alloc.allocate(_capacity);
                }
                for (size_t i = 0 ; i < _size ; i++)
                  _alloc.construct(&_buff[i], val);
                // for(size_t i = 0 ; i < _size ; i++)
                //   _alloc.construct(&_buff[i], val);
                // _alloc.deallocate(_buff);
                // _buff = _alloc.allocate(n);
                // for (size_t i = 0; i < n ; i++)
                //   _alloc.construct(&buff[i],val);
                // _size = n;
            }
            
            allocator_type get_allocator() const
            {
              return _alloc;
            }
            iterator begin()
            {
              return iterator(_buff);
            }
            const_iterator begin()const
            {
              return const_iterator(_buff);
            }
            iterator end()
            {
              return iterator(_buff + _size);
            }
            const_iterator end()const
            {
              return const_iterator(_buff + _size);
            }
            reverse_iterator rbegin()
            {
              reverse_iterator tmp(end());
              return tmp;
            }
            const_reverse_iterator rbegin() const
            {
              const_reverse_iterator tmp(end());
              return tmp;
            }
            reverse_iterator rend()
            {
              reverse_iterator tmp(begin());
              return tmp;
            }
            const_reverse_iterator rend() const
            {
              const_reverse_iterator tmp(begin());
              return tmp;
            }
            // capacity:
            size_type size() const
            {
              return _size;
            }
            size_type max_size() const
            {
              return _alloc.max_size();
            }
            void resize (size_type n, value_type val = value_type())
            {
              if (n < _size)
              {
                for (size_type i = n ; i < _size ; i++)
                  _alloc.destroy(&_buff[i]);
                
              }
              if (n > _size)
              {
                reserve(n);
                for (size_type i = _size ; i < n ; i++ )
                  _alloc.construct(&_buff[i],val);
                
              }
              _size = n;
            }

 
            size_type capacity() const
            {
              return _capacity;
            }
            bool empty() const
            {
              return _size == 0;
            }
            void reserve(size_type n)
            {
              if (n > _capacity)
              {
                pointer _tmp = _alloc.allocate(n);
                for ( size_t i = 0 ; i < _size ; i++)
                {
                  _alloc.construct(&_tmp[i],_buff[i]);
                  _alloc.destroy(&_buff[i]);
                }
                if (!_buff)
                  _alloc.deallocate(_buff,_capacity);
                  _buff = _tmp;
                  _capacity = n;
              }
            }
            // element access:
            reference operator[](size_type n)
            {
              return _buff[n];
            }
            const_reference operator[](size_type n) const
            {
              return _buff[n];
            }
            const_reference at(size_type n) const
            {
              if (n < _size)
                return _buff[n];
              else
                throw std::out_of_range("out of range");
            
            }
            reference at(size_type n)
            {
              if (n < _size)
                return _buff[n];
              else
                throw std::out_of_range("out of range");
            }
            reference front()
            {
              return _buff[0];
            }
            const_reference front() const 
            {
              return _buff[0];
            }
            reference back()
            {
              return _buff[_size - 1];
            }
            const_reference back() const
            {
              return _buff[_size - 1];
            }
            // modifiers:
            void push_back (const value_type& val)
            {
              if (_size == _capacity)
              {
                if (_capacity == 0)
                  reserve(1);
                else
                  reserve (_capacity * 2);            
              }
              _alloc.construct(&_buff[_size],val);
              ++_size;
            }
            void pop_back()
            {
              _alloc.destroy(&_buff[_size--]);
              
            }
            iterator insert(iterator position, const value_type& x)
            {
              size_t len = 0;
              if (position.get_pointer())
                len = std::distance(begin(),position);

              if (_size >= _capacity)
              {
                if (_capacity == 0)
                  reserve(1);
                else
                  reserve (_capacity * 2);            
              }
              for (size_t i = _size ; i > len ; i--)
              {
                _buff[i] = _buff[i - 1];
              }
              _buff[len] = x;
              ++_size;
              return &_buff[len];
            }
            void insert (iterator position, size_type n, const value_type& x)
            {
             size_type index = 0;
                if (position.get_pointer())
                  index = std::distance(begin(), position);
                if (_size + n > _capacity)
                {
                  if (n > _size)
                    reserve(n + _size);
                  else
                    reserve(_capacity * 2);
                }
                for (size_type i = _size; i > index; i--){
                  _alloc.construct(&_buff[i + n - 1], _buff[i - 1]);
                }
                for (size_type i = index; i < index + n; i++)
                  _alloc.construct(&_buff[i], x);
                _size += n;
            }
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last , typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
              size_type n = last - first;
              size_type index = 0;
                if (position.get_pointer())
                  index = std::distance(begin(), position);
                if (_size + n > _capacity)
                {
                  if (n > _size)
                    reserve(n + _size);
                  else
                    reserve(_capacity * 2);
                }
                for (size_type i = _size; i > index; i--){
                  _buff[i + n - 1] = _buff[i - 1];
                }
                for (size_type i = index; i < index + n && first != last; i++,first++)
                  _alloc.construct(&_buff[i],*first);
                _size += n;
            }

            iterator erase(iterator position)
            {
              size_t len = 0;
              if (position.get_pointer())
                len = std::distance(begin(),position);
              for (size_t i = len ; i < _size - 1 ; i++)
              {
                _buff[i] = _buff[i + 1];
              }
              _alloc.destroy(&_buff[_size - 1]);
              --_size;
              return position;
            }
            iterator erase(iterator first, iterator last)
            {
              size_t len = std::distance(first,last);
              for (size_t i = 0 ; i < len ; i++)
              {
                erase(first);
              }
              return first;
              
            }
             void swap (vector& a)
             {
                value_type *tmpBuff;
                size_type tmpSize;
                size_type tmpCapacity;

                tmpBuff = _buff;
                tmpSize = _size;
                tmpCapacity = _capacity;

                this->_buff = a._buff;
                this->_size = a._size;
                this->_capacity = a._capacity;

                a._buff = tmpBuff;
                a._size = tmpSize;
                a._capacity = tmpCapacity;
             }
            static void swap(reference x, reference y)
            {
              value_type tmp = x;
              x = y;
              y = tmp;
            } 
            void clear()
            {
              for (size_t i = 0 ; i < _size ; i++)
                _alloc.destroy(&_buff[i]);
              _size = 0;
            }

          
            // constructors
            private :
                allocator_type _alloc;
                pointer _buff;
                size_type _size;
                size_type _capacity;
    };

   // std::equal
    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
      size_t len = std::distance(first1,last1);
      for (size_t i = 0 ; i < len ; i++)
      {
        if (first1[i] != first2[i])
          return false;
      }
      return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
      size_t len = std::distance(first1,last1);
      for (size_t i = 0 ; i < len ; i++)
      {
        if (!pred(first1[i],first2[i]))
          return false;
      }
      return true;
    }
    //lexicographical_compare
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
      size_t len1 = std::distance(first1,last1);
      size_t len2 = std::distance(first2,last2);
      if (len1 < len2)
        return true;
      else if (len1 > len2)
        return false;
      else
      {
        for (size_t i = 0 ; i < len1 ; i++)
        {
          if (first1[i] < first2[i])
            return true;
          else if (first1[i] > first2[i])
            return false;
        }
        return false;
      }
    };

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
      size_t len1 = std::distance(first1,last1);
      size_t len2 = std::distance(first2,last2);
      if (len1 < len2)
        return true;
      else if (len1 > len2)
        return false;
      else
      {
        for (size_t i = 0 ; i < len1 ; i++)
        {
          if (comp(first1[i],first2[i]))
            return true;
          else if (comp(first2[i],first1[i]))
            return false;
        }
        return false;
      }
    };

    template <class U, class alloc>
  	bool operator==(const vector<U,alloc>& x, const vector<U,alloc>& y)
      {
        if (x.size() != y.size())
          return false;
        for (size_t i = 0 ; i < x.size() ; i++)
        {
          if (x[i] != y[i])
          return false;
        }
          return true;
      };
      template <class U, class alloc>
      bool operator< (const vector<U,alloc>& y,const vector<U,alloc>& x)
      {
        return ft::lexicographical_compare(y.begin(),y.end(),x.begin(),x.end());
      };

      template <class U, class alloc>
      bool operator!=(const vector<U,alloc>& x,const vector<U,alloc>& y)
        {
          if (x.size() != y.size())
            return true;
          for (size_t i = 0 ; i < x.size() ; i++)
          {
            if (x[i] != y[i])
              return true;
          }
          return false;
        };
     template <class U, class alloc>
        bool operator> (const vector<U,alloc>& y,const vector<U,alloc>& x)
        {
          return ft::lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());
        };
      template <class U, class alloc>
      bool operator>=(const vector<U,alloc>& x, const vector<U,alloc>& y)
      {
        return !(x < y);
      };
      template <class U, class alloc>
      bool operator<=(const vector<U,alloc>& x, const vector<U,alloc>& y)
      {
        return !(x > y);
      };

      template <class T, class Alloc>
      void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
      {
        x.swap(y);
      }


}
