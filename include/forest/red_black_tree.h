#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

namespace forest {
        namespace red_black {
                template <typename key_t, typename value_t>
                struct node {
                        node(key_t key, value_t value) {
                                this->key = key;
                                this->value = value;
                                this->parent = nullptr;
                                this->left = nullptr;
                                this->right = nullptr;
                        }
                        key_t key;
                        value_t value;
                        node *parent;
                        node *left;
                        node *right;
                };
                template <typename key_t, typename value_t>
                class tree {
                private:
                        node <key_t, value_t> *root;
                        void pre_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                std::cout << n->key << " " << n->value << std::endl;
                                pre_order_traversal(n->left);
                                pre_order_traversal(n->right);
                        }
                        void in_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                in_order_traversal(n->left);
                                std::cout << n->key << " " << n->value << std::endl;
                                in_order_traversal(n->right);
                        }
                        void post_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                post_order_traversal(n->left);
                                post_order_traversal(n->right);
                                std::cout << n->key << " " << n->value << std::endl;
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
                        bool contains(key_t key) {
                                return (search(key) == nullptr) ? true : false;
                        }
                        node <key_t, value_t> *search(key_t key) {
                                node <key_t, value_t> *n = root;
                                while (n != nullptr) {
                                        if (key > n->key) {
                                                n = n->right;
                                        } else if (key < n->key) {
                                                n = n->left;
                                        } else {
                                                return n;
                                        }
                                }
                                return nullptr;
                        }
                };
        }
}

#endif
