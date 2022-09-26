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
        explicit map(const Compare &comp = Compare(), const Allocator & = Allocator());

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = Compare(), const Allocator & = Allocator());

        map(const map<Key, T, Compare, Allocator> &x);
        ~map();
        map<Key, T, Compare, Allocator> &operator=(const map<Key, T, Compare, Allocator> &x);

        // iterators;
        iterator begin();   
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // CAPACITY
        bool empty() const
        {
            return tree.empty();
        }
        size_type size() const
        {
            return tree.size();
        }
        size_type max_size() const
        {
            return tree.max_size();
        }

        // 23.3.1.2 element access:
        T& operator[](const key_type& x)
        {
            return (*((this->insert(ft::make_pair(x, T()))).first)).second;
        }

        // modifiers:
        pair<iterator, bool> insert(const value_type& x);
        iterator insert(iterator position, const value_type& x);

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);

        void erase(iterator position);
        size_type erase(const key_type& x);
        void erase(iterator first, iterator last);
        void swap(map<Key,T,Compare,Allocator>&);
        void clear();

        // observers:
        key_compare key_comp() const;
        value_compare value_comp() const

        // 23.3.1.3 map operations:
        iterator find(const key_type& x);
        const_iterator find(const key_type& x) const;
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
