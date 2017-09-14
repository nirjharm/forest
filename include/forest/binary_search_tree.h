#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

namespace forest {
        template <typename key_t, typename value_t>
        class binary_search_tree {
        private:
                struct node {
                        node(key_t key, value_t value) {
                                this->key = key;
                                this->value = value;
                                this->left = nullptr;
                                this->right = nullptr;
                        }
                        key_t key;
                        value_t value;
                        node *left;
                        node *right;
                };
                node *root;
        public:
                binary_search_tree() {

                }
                ~binary_search_tree() {

                }
                void pre_order_traversal() {

                }
                void in_order_traversal() {

                }
                void post_order_traversal() {

                }
        };
}

#endif
