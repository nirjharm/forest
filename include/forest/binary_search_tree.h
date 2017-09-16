#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

namespace forest {
        namespace binary_search {
                template <typename key_t, typename value_t>
                struct node {
                        key_t key;
                        value_t value;
                        node *parent;
                        node *left;
                        node *right;
                        node(key_t key, value_t value) {
                                this->key = key;
                                this->value = value;
                                this->parent = nullptr;
                                this->left = nullptr;
                                this->right = nullptr;
                        }
                };
                template <typename key_t, typename value_t>
                class tree {
                private:
                        node <key_t, value_t> *root;
                        void pre_order_traversal(node <key_t, value_t> *x) {
                                if (x == nullptr) return;
                                std::cout << x->key << " " << x->value << std::endl;
                                pre_order_traversal(x->left);
                                pre_order_traversal(x->right);
                        }
                        void in_order_traversal(node <key_t, value_t> *x) {
                                if (x == nullptr) return;
                                in_order_traversal(x->left);
                                std::cout << x->key << " " << x->value << std::endl;
                                in_order_traversal(x->right);
                        }
                        void post_order_traversal(node <key_t, value_t> *x) {
                                if (x == nullptr) return;
                                post_order_traversal(x->left);
                                post_order_traversal(x->right);
                                std::cout << x->key << " " << x->value << std::endl;
                        }
                public:
                        tree() {
                                root = nullptr;
                        }
                        ~tree() {

                        }
                        void pre_order_traversal() {
                                pre_order_traversal(root);
                        }
                        void in_order_traversal() {
                                in_order_traversal(root);
                        }
                        void post_order_traversal() {
                                post_order_traversal(root);
                        }
                        void insert(key_t key, value_t value) {
                                node <key_t, value_t> *current = root;
                                node <key_t, value_t> *previous = nullptr;
                                while(current!=nullptr) {
                                        previous = current;
                                        if (key > current->key) {
                                                current = current->right;
                                        } else if (key < current->key) {
                                                current = current->left;
                                        }
                                }
                                current = new node <key_t, value_t> (key, value);
                                current->parent = previous;
                                if(previous == nullptr) {
                                        root = current;
                                } else if (current->key > previous->key) {
                                        previous->right = current;
                                } else if (current->key < previous->key) {
                                        previous->left = current;
                                }
                        }
                        bool contains(key_t key) {
                                return (search(key) == nullptr) ? true : false;
                        }
                        node <key_t, value_t> *search(key_t key) {
                                node <key_t, value_t> *x = root;
                                while (x != nullptr) {
                                        if (key > x->key) {
                                                x = x->right;
                                        } else if (key < x->key) {
                                                x = x->left;
                                        } else {
                                                return x;
                                        }
                                }
                                return nullptr;
                        }
                };
        }
}

#endif
