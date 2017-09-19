/**
 * @file binary_search_tree.h
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <algorithm>
#include <queue>

/**
 * @brief The forest library namespace
 */
namespace forest {
        /**
         * @brief The binary search tree namespace
         */
        namespace binary_search_tree {
                /**
                 * @brief A struct template that represents a node of a binary search tree
                 */
                template <typename key_t, typename value_t>
                struct node {
                        key_t key;     ///< The key of the node
                        value_t value; ///< The value of the node
                        node *parent;  ///< A pointer to the parent of the node
                        node *left;    ///< A pointer to the left child of the node
                        node *right;   ///< A pointer to the right child of the node
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
                /**
                 * @brief A template class that represents a binary search tree
                 */
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
                        /**
                         * @brief Performs a Pre Order Traversal starting from the root node
                         * @return void
                         */
                        void pre_order_traversal() {
                                pre_order_traversal(root);
                        }
                        /**
                         * @brief Performs a In Order Traversal starting from the root node
                         * @return void
                         */
                        void in_order_traversal() {
                                in_order_traversal(root);
                        }
                        /**
                         * @brief Performs a Post Order Traversal starting from the root node
                         * @return void
                         */
                        void post_order_traversal() {
                                post_order_traversal(root);
                        }
                        /**
                         * @brief Performs a Breadth First Traversal starting from the root node
                         * @return void
                         */
                        void breadth_first_traversal() {
                                breadth_first_traversal(root);
                        }
                        /**
                         * @brief Inserts a new node into the binary search tree
                         * @param key The key for the new node
                         * @param value The value for the new node
                         * @return void
                         */
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
                        /**
                         * @brief Performs a binary search starting from the root node
                         */
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
                        /**
                         * @brief Finds the node with the minimum key
                         * @return true if the node with the minimum key exists and false otherwise
                         */
                        bool minimum(key_t *key, value_t *value) {
                                node <key_t, value_t> *x = root;
                                if (x == nullptr) return false;
                                while(x->left != nullptr) x = x->left;
                                *key = x->key;
                                *value = x->value;
                                return true;
                        }
                        /**
                         * @brief Finds the node with the maximum key
                         * @return true if the node with the maximum key exists and false otherwise
                         */
                        bool maximum(key_t *key, value_t *value) {
                                node <key_t, value_t> *x = root;
                                if (x == nullptr) return false;
                                while(x->right != nullptr) x = x->right;
                                *key = x->key;
                                *value = x->value;
                                return true;
                        }
                        /**
                         * @brief Finds the height of the tree
                         * @return The height of the subtree starting from the root node
                         */
                        unsigned long long height() {
                                return height(root);
                        }
                        /**
                         * @brief Finds the size of the tree
                         * @return The size of the subtree starting from the root node
                         */
                        unsigned long long size() {
                                return size(root);
                        }
                        /**
                         * @brief Finds if the tree is empty
                         * @return true if the tree is empty and false otherwise
                         */
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
