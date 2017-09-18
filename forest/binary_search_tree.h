#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <algorithm>
#include <queue>

namespace forest {
        namespace binary_search_tree {
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
                        void info() {
                                std::cout << this->key << "\t";
                                if (this->left != nullptr) {
                                        std::cout << this->left->key << "\t";
                                } else {
                                        std::cout << "null" << "\t";
                                }
                                if (this->right != nullptr) {
                                        std::cout << this->right->key << "\t";
                                } else {
                                        std::cout << "null" << "\t";
                                }
                                if (this->parent != nullptr) {
                                        std::cout << this->parent->key << std::endl;
                                } else {
                                        std::cout << "null" << std::endl;
                                }
                        }
                };
                template <typename key_t, typename value_t>
                class tree {
                private:
                        node <key_t, value_t> *root;
                        void pre_order_traversal(node <key_t, value_t> *x) {
                                if (x == nullptr) return;
                                x->info();
                                pre_order_traversal(x->left);
                                pre_order_traversal(x->right);
                        }
                        void in_order_traversal(node <key_t, value_t> *x) {
                                if (x == nullptr) return;
                                in_order_traversal(x->left);
                                x->info();
                                in_order_traversal(x->right);
                        }
                        void post_order_traversal(node <key_t, value_t> *x) {
                                if (x == nullptr) return;
                                post_order_traversal(x->left);
                                post_order_traversal(x->right);
                                x->info();
                        }
                        void breadth_first_traversal(node <key_t, value_t> *x) {
                                std::queue <node <key_t, value_t> *> queue;
                                if (x == nullptr) return;
                                queue.push(x);
                                while(queue.size() > 0) {
                                        node <key_t, value_t> *y = queue.front();
                                        y->info();
                                        queue.pop();
                                        if (y->left != nullptr) queue.push(y->left);
                                        if (y->right != nullptr) queue.push(y->right);
                                }
                        }
                        unsigned long long height(node <key_t, value_t> *x) {
                                if (x == nullptr) return 0;
                                return std::max(height(x->left), height(x->right)) + 1;
                        }
                        unsigned long long size(node <key_t, value_t> *x) {
                                if (x == nullptr) return 0;
                                return size(x->left) + size(x->right) + 1;
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
                        void breadth_first_traversal() {
                                breadth_first_traversal(root);
                        }
                        void insert(key_t key, value_t value) {
                                node <key_t, value_t> *current = root;
                                node <key_t, value_t> *parent = nullptr;
                                while(current!=nullptr) {
                                        parent = current;
                                        if (key > current->key) {
                                                current = current->right;
                                        } else if (key < current->key) {
                                                current = current->left;
                                        }
                                }
                                current = new node <key_t, value_t> (key, value);
                                current->parent = parent;
                                if(parent == nullptr) {
                                        root = current;
                                } else if (current->key > parent->key) {
                                        parent->right = current;
                                } else if (current->key < parent->key) {
                                        parent->left = current;
                                }
                        }
                        bool search(key_t key, value_t *value) {
                                node <key_t, value_t> *x = root;
                                while (x != nullptr) {
                                        if (key > x->key) {
                                                x = x->right;
                                        } else if (key < x->key) {
                                                x = x->left;
                                        } else {
                                                *value = x->value;
                                                return true;
                                        }
                                }
                                return false;
                        }
                        bool minimum(key_t *key, value_t *value) {
                                node <key_t, value_t> *x = root;
                                if (x == nullptr) return false;
                                while(x->left != nullptr) x = x->left;
                                *key = x->key;
                                *value = x->value;
                                return true;
                        }
                        bool maximum(key_t *key, value_t *value) {
                                node <key_t, value_t> *x = root;
                                if (x == nullptr) return false;
                                while(x->right != nullptr) x = x->right;
                                *key = x->key;
                                *value = x->value;
                                return true;
                        }
                        unsigned long long height() {
                                return height(root);
                        }
                        unsigned long long size() {
                                return size(root);
                        }
                        bool empty() {
                                if (root == nullptr) {
                                        return true;
                                } else {
                                        return false;
                                }
                        }
                };
        }
}

#endif
