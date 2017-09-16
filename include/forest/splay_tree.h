#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream>

namespace forest {
        namespace splay {
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
                                // std::cout << n->key << " " << n->value << std::endl;
                                pre_order_traversal(n->left);
                                pre_order_traversal(n->right);
                        }
                        void in_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                in_order_traversal(n->left);
                                std::cout << n->key << "\t";
                                if (n->left != nullptr) {
                                        std::cout << n->left->key << "\t";
                                } else {
                                        std::cout << "null" << "\t";
                                }
                                if (n->right != nullptr) {
                                        std::cout << n->right->key << "\t";
                                } else {
                                        std::cout << "null" << "\t";
                                }
                                if (n->parent != nullptr) {
                                        std::cout << n->parent->key << std::endl;
                                } else {
                                        std::cout << "null" << std::endl;
                                }
                                in_order_traversal(n->right);
                        }
                        void post_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                post_order_traversal(n->left);
                                post_order_traversal(n->right);
                                // std::cout << n->key << " " << n->value << std::endl;
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
                        void left_rotate(node <key_t, value_t> *x) {
                                node <key_t, value_t> *y = x->right;
                                if(y != nullptr) {
                                        x->right = y->left;
                                        if(y->left) y->left->parent = x;
                                        y->parent = x->parent;
                                }

                                if(x->parent == nullptr) {
                                        root = y;
                                } else if (x == x->parent->left) {
                                        x->parent->left = y;
                                } else {
                                        x->parent->right = y;
                                }
                                if(y != nullptr) {
                                        y->left = x;
                                }
                                x->parent = y;
                        }
                        void right_rotate(node <key_t, value_t> *x) {
                                node <key_t, value_t> *y = x->left;
                                if (y != nullptr) {
                                        x->left = y->right;
                                        if (y->right) y->right->parent = x;
                                        y->parent = x->parent;
                                }
                                if(x->parent == nullptr) {
                                        root = y;
                                } else if (x == x->parent->left) {
                                        x->parent->left = y;
                                } else {
                                        x->parent->right = y;
                                }
                                if(y != nullptr) {
                                        y->right = x;
                                }
                                x->parent = y;
                        }
                        void splay(node <key_t, value_t> *x) {
                                while (x->parent) {
                                        if (x->parent->parent == nullptr) {
                                                if (x->parent->left == x) {
                                                        right_rotate(x->parent);
                                                } else if (x->parent->right == x){
                                                        left_rotate(x->parent);
                                                }
                                        } else if (x->parent->left == x && x->parent->parent->left == x->parent) {
                                                right_rotate(x->parent->parent);
                                                right_rotate(x->parent);
                                        } else if (x->parent->right == x && x->parent->parent->right == x->parent) {
                                                left_rotate(x->parent->parent);
                                                left_rotate(x->parent);
                                        } else if (x->parent->left == x && x->parent->parent->right == x->parent) {
                                                right_rotate(x->parent);
                                                left_rotate(x->parent);
                                        } else if (x->parent->right == x && x->parent->parent->left == x->parent){
                                                left_rotate(x->parent);
                                                right_rotate(x->parent);
                                        }
                                }
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
                                splay(current);
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
