
#include <iostream>


namespace ft
{
    template < typename val_type, typename node_type>
    class Bidirectional_iterator
    {
        private:
            node_type *node;
            node_type *node_root;

        public:

            //GETTERS
            node_type *get_node() const
            {
                return node;
            };
            node_type *get_parent() const
            {
                return node_root;
            };

            //CONSTRCTORS
            Bidirectional_iterator()
            {
                node = NULL;
                node_root = NULL;
            };

            Bidirectional_iterator(Bidirectional_iterator const &other)
            {
                node = other.get_node();
                node_root = other.get_parent();
            };

            Bidirectional_iterator(node_type *node, node_type *node_root)
            {
                this->node = node;
                this->parent = node_root;
            };

            ~Bidirectional_iterator()
            {
            };

            //Comparisons

            bool operator==(Bidirectional_iterator const &other) const
            {
                return (node == other.get_node());
            };

            bool operator!=(Bidirectional_iterator const &other) const
            {
                return (node != other.get_node());
            };
            //OPERATORS
            Bidirectional_iterator &operator=(Bidirectional_iterator const &other)
            {
                node = other.get_node();
                node_root = other.get_parent();
                return *this;
            };

            Bidirectional_iterator min_value(node_type *node)
            {

            }
            Bidirectional_iterator &operator++()
            {
                if (node->right)
                {
                    node = node->right;
                    while (node->left)
                        node = node->left;
                }
                else
                {
                }
                return *this;
            };
            Bidirectional_iterator &operator--()
            {
                
            }



    };
};