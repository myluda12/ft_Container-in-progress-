#pragma once
#include "avl.hpp"
#include <utility>
#include "reverse_iterator.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>>
    class map
    {
    public: // types:                
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef ptrdiff_t difference_type;
        typedef ft::node<value_type,allocator_type> node_type;
        typedef typename ft::bidirectional_iterator<value_type, node_type *> iterator;
        typedef typename ft::bidirectional_iterator<const value_type, node_type *> const_iterator;
        typedef size_t size_type;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::avl<value_type, key_compare, allocator_type> tree_type;

        size_type size;
        node_type *root;


        class value_compare : public binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };
        // 23.3.1.1 construct/copy/destroy:
        explicit map(const Compare &comp = Compare(), const Allocator &alloca = Allocator())
        {
            size = 0;
            root = NULL;
            compare = comp;
            alloc = alloca;

        }

         template<class InputIterator>
         Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),const allocator_type &alloc = allocator_type(),
         typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
          {
           size = 0;
           root = NULL;
           compare = comp;
           alloc = alloca;
           for (InputIterator it = first; it != last; it++)
           {
               root = tree.insert(root, NULL, *it);
               size++;
           }
          }


        map(const map<Key, T, Compare, Allocator> &x)
        {
            root = NULL;
            size = 0;
            *this = x;
        }
        ~map()
        {
            root = tree.Deleteall(root);
        }
        map<Key, T, Compare, Allocator> &operator=(const map<Key, T, Compare, Allocator> &x)
        {
            if (this == &x)
                return *this;
            tree.Deleteall(root);
            size = 0;
            for (const_iterator it = x.begin(); it != x.end(); it++)
            {
                root = tree.insert(root, NULL, *it);
                size++;
            }
            return *this;
        }

        // iterators;
        iterator begin()
        {   
            return iterator(root,tree.findmin(root));
        }
        const_iterator begin() const
        {
            return const_iterator(root,tree.findmin(root));
        }
        iterator end()
        {
            return iterator(root,tree.findmax(root));
        }
        const_iterator end() const
        {
            return const_iterator(root,tree.findmax(root));
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        // CAPACITY
        bool empty() const
        {
            return size == 0;
        }
        size_type size() const
        {
            return size;
        }
        size_type max_size() const
        {
            return alloc.max_size();
        }
        //TOOOO REMIIIIIND PLEASE
         pair<const iterator, const iterator>equal_range(const key_type &k) const
         {
            return pair<const iterator, const iterator>(lower_bound(k),upper_bound(k));
         }
         pair< iterator,  iterator>equal_range(const key_type &k) 
         {
           return pair< iterator,  iterator>(lower_bound(k),upper_bound(k));
         }
        // 23.3.1.2 element access:
        T& operator[](const key_type& x)
        {
            return (*((this->insert(ft::make_pair(x, T()))).first)).second;
        }

        // modifiers:
        pair<iterator, bool> insert(const value_type &k)
        {
            iterator it = find(k.first);
            if(it!= end())
                return pair<iterator,bool>(it, false);
            root = tree.insert(root, NULL, k);
             size++;
             return pair<iterator,bool>(begin(), true);
        }

        iterator insert(iterator position, const value_type &k)
            {
                iterator it = find(k.first);
                if (it != end())
                    return position;
                root = tree.insert(root, NULL, k);
                size++;
                return begin();
            }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
        {
            for (InputIterator it = first; it != last; it++)
            {
                root = tree.insert(root, NULL, *it);
                size++;
            }
        }

        // void erase(iterator position)
        // {
        //     root = tree.Delete(root, position.node);
        //     size--;
        // }
        // size_type erase(const key_type& x)
        // {
        // }
        // void erase(iterator first, iterator last);

        void swap(map<Key,T,Compare,Allocator>&)
        {
            std::swap(root, x.root);
            std::swap(size, x.size);
            std::swap(alloc, x.alloc);
            std::swap(compare, x.compare);
        }
        void clear()
        {
            size = 0;
        }

        // observers:
        key_compare key_comp() const
        {
            return compare;
        }
        value_compare value_comp() const
        {
            return value_compare(compare);
        }

        // 23.3.1.3 map operations:
        iterator find(const key_type &k)
        {
            node * found = tree.find(root ,k);
            if (found != NULL)
                return iterator(root, found);
            return end();
        }
        const iterator find(const key_type &k) const
        {
            node * found = tree.find(root ,k);
            if (found != NULL)
                return const_iterator(root, found);
            return end();
        }

        size_type count(const key_type& x) const;

        iterator lower_bound(const key_type& x);
        const_iterator lower_bound(const key_type& x) const;
        iterator upper_bound(const key_type& x);
        const_iterator upper_bound(const key_type& x) const;

        private:
            key_compare		compare;
            allocator_type	alloc;
            tree_type		tree;
    };

};
