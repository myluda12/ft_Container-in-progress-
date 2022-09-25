#include <iostream>
#include "map.hpp"
#include "iterator_traits.hpp"
namespace ft 
{
    
template <class T,class alloc = std::allocator<T> >
struct Node
{
    Node    *parent;
    Node    *left;
    Node    *right;
    ft::pair<const Key, T> *data;
    int     height;
    int     bf;

    Node(T value) {
        data = value;
        parent = NULL;
        left = NULL;
        right = NULL;
        height = 1;   
        bg = 0;
    }
};


template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
class AVLTree
{
        typedef Node<Key, T> node;
        typedef ft::pair<const Key, T> pair;
        typedef typename Alloc::template rebind<Node>::other rebind_allocator;
        typedef typename Alloc::template rebind<pair>::other _allocator;
        rebind_allocator nodeall;
        _allocator Pair;
        Compare comp;
    private:
        Node *root;
    
    public:
    AVLTree()
    {
        this->root = NULL;
    }

    Node *create_node(T data) {
        // new will be  changed with allocator<Node> (rebind)
        Node *new_node = new Node(data);
        return new_node;
    }

    void delete_node(Node *n) {
        // delete will be changed by allocator<Node>.deallocate()
        delete n;
        n = NULL;
    }

    int calcule_height(Node *parent)
    {
       if(parent->left && parent->right)
       {
            if (parent->left->height < parent->right->height)
                return parent->right->height + 1;
            else return  parent->left->height + 1;
        }
        else if(parent->left && parent->right == NULL)
        {
           return parent->left->height + 1;
        }
        else if(parent->left ==NULL && parent->right)
        {
            return parent->right->height + 1;
         }
         return 0;

    }

    int balance_factor(Node *parent)
    {
        if (parent->left && parent->right)
        {
            if  (parent->left->height < parent->right->height)
                return parent->right->height - parent->left->height;
            else
                return parent->left->height - parent->right->height;
        }
        else if (parent->left && parent->right == NULL)
            return parent->left->height + 1;
        else if (parent->left == NULL && parent->right)
            return parent->right->height + 1;
        
        return 0;
    }
    
    Node *left_left_rotation(Node *parent)
    {
        Node *temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        parent->height = calcule_height(parent);
        temp->height = calcule_height(temp);
        return temp;
    }

    Node *right_right_rotation(Node *parent)
    {
        Node *temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        parent->height = calcule_height(parent);
        temp->height = calcule_height(temp);
        return temp;
    }

    Node *left_right_rotation(Node *parent)
    {
        Node *temp = parent->left;
        parent->left = right_right_rotation(temp);
        return left_left_rotation(parent);
    }
    Node *right_left_rotation(Node *parent)
    {
        Node *temp = parent->right;
        parent->right = left_left_rotation(temp);
        return right_right_rotation(parent);
    }

    Node *insert(Node *parent,T data)
    {
        if (parent == NULL)
        {
            Node *n = new Node(data);
            n->height = 1;
            return n;
            
        }
        else
        {
            if (data < parent->data)
            {
                parent->left = insert(parent->left,data);
                parent->left->parent = parent;
            }
            else if (data > parent->data)
            {
                parent->right = insert(parent->right,data);
                parent->right->parent = parent;
            }
            
        }
        parent->height = calcule_height(parent);
        parent->bf = balance_factor(parent);
        if (parent->bf == 2)
        {
            if (balance_factor(parent->left) == 1)
                return left_left_rotation(parent);
            else
                return left_right_rotation(parent);
        }
        else if (parent->bf == -2)
        {
            if (balance_factor(parent->right) == -1)
                return right_right_rotation(parent);
            else
                return right_left_rotation(parent);
        }
        return parent;
        
    }
    void delete(Node *n) {
        // 
    }
    void search(T value) {
        // 
    }
    Node *min(Node *n) {
        // travers left values
    }
    Node *max() {

    }
    Node *successor(Node *n) {
        // if n->rigth !=null
            // return min(n->rigth)
        // Node *p = n->parent;
        // while (p != NULL && n == p->right) {
        //     n = p;
        //     p = p->p;
        // }
        // return p;
    }
};
};