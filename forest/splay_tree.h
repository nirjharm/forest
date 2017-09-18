#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream>
#include <algorithm>
#include <queue>

namespace forest {
        namespace splay_tree {
                template <typename key_t>
                struct node {
                        key_t key;
                        node *parent;
                        node *left;
                        node *right;
                        node(key_t key) {
                                this->key = key;
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
                template <typename key_t>
                class tree {
                private:
                        node <key_t> *root;
                        void pre_order_traversal(node <key_t> *x) {
                                if (x == nullptr) return;
                                x->info();
                                pre_order_traversal(x->left);
                                pre_order_traversal(x->right);
                        }
                        void in_order_traversal(node <key_t> *x) {
                                if (x == nullptr) return;
                                in_order_traversal(x->left);
                                x->info();
                                in_order_traversal(x->right);
                        }
                        void post_order_traversal(node <key_t> *x) {
                                if (x == nullptr) return;
                                post_order_traversal(x->left);
                                post_order_traversal(x->right);
                                x->info();
                        }
                        void breadth_first_traversal(node <key_t> *x) {
                                std::queue <node <key_t> *> queue;
                                if (x == nullptr) return;
                                queue.push(x);
                                while(queue.size() > 0) {
                                        node <key_t> *y = queue.front();
                                        y->info();
                                        queue.pop();
                                        if (y->left != nullptr) queue.push(y->left);
                                        if (y->right != nullptr) queue.push(y->right);
                                }
                        }
                        unsigned long long height(node <key_t> *x) {
                                if (x == nullptr) return 0;
                                return std::max(height(x->left), height(x->right)) + 1;
                        }
                        unsigned long long size(node <key_t> *x) {
                                if (x == nullptr) return 0;
                                return size(x->left) + size(x->right) + 1;
                        }
                        void left_rotate(node <key_t> *x) {
                                node <key_t> *y = x->right;
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
                        void right_rotate(node <key_t> *x) {
                                node <key_t> *y = x->left;
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
                        void splay(node <key_t> *x) {
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
                        void insert(key_t key) {
                                node <key_t> *current = root;
                                node <key_t> *parent = nullptr;
                                while(current!=nullptr) {
                                        parent = current;
                                        if (key > current->key) {
                                                current = current->right;
                                        } else if (key < current->key) {
                                                current = current->left;
                                        }
                                }
                                current = new node <key_t> (key);
                                current->parent = parent;
                                if(parent == nullptr) {
                                        root = current;
                                } else if (current->key > parent->key) {
                                        parent->right = current;
                                } else if (current->key < parent->key) {
                                        parent->left = current;
                                }
                                splay(current);
                        }
                        bool contains(key_t key) {
                                return (search(key) != nullptr) ? true : false;
                        }
                        node <key_t> *search(key_t key) {
                                node <key_t> *x = root;
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
                        node <key_t> *minimum() {
                                node <key_t> *x = root;
                                if (x == nullptr) return nullptr;
                                while(x->left != nullptr) x = x->left;
                                std::cout << "ok" << std::endl;
                                return x;
                        }
                        node <key_t> *maximum() {
                                node <key_t> *x = root;
                                if (x == nullptr) return nullptr;
                                while(x->right != nullptr) x = x->right;
                                return x;
                        }
                        unsigned long long height() {
                                return height(root);
                        }
                        unsigned long long size() {
                                return size(root);
                        }
                };
        }
}

#endif
