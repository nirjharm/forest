/**
 * @file red_black_tree.h
 */

#ifndef red_black_TREE_H
#define red_black_TREE_H

#include <iostream>
#include <algorithm>
#include <queue>

/**
 * @brief The forest library namespace
 */
namespace forest {
        /**
         * @brief The red black tree namespace
         */
        namespace red_black_tree {
                enum color_t {red, black};
                /**
                 * @brief A struct template that represents a node of a red black tree
                 */
                template <typename key_t, typename value_t>
                struct node {
                        key_t key;     ///< The key of the node
                        value_t value; ///< The value of the node
                        color_t color; ///< The color of the node
                        node *parent;  ///< A pointer to the parent of the node
                        node *left;    ///< A pointer to the left child of the node
                        node *right;   ///< A pointer to the right child of the node
                        /**
                         * @brief Constructor of a red black tree node
                         */
                        node(key_t key, value_t value, color_t color) {
                                this->key = key;
                                this->value = value;
                                this->color = color;
                                this->parent = nullptr;
                                this->left = nullptr;
                                this->right = nullptr;
                        }
                        /**
                         * @brief Prints to the std::cout information about the node
                         */
                        void info() const {
                                std::cout << this->key << "\t";
                                if (this->color == red) {
                                        std::cout << "red" << "\t";
                                } else if (this->color == black) {
                                        std::cout << "black" << "\t";
                                }
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
                 * @brief A template class that represents a red black tree
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
                        void left_rotate(node <key_t, value_t> *x) {
                                node <key_t, value_t> *y = x->right;
                                if(y != nullptr) {
                                        x->right = y->left;
                                        if(y->left != nullptr) y->left->parent = x;
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
                                        if (y->right != nullptr) y->right->parent = x;
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
                        node <key_t, value_t> *find_sibling(node <key_t, value_t> *x) {
                                if (x == find_parent(x)->left) {
                                        return find_parent(x)->right;
                                } else if (x == find_parent(x)->right) {
                                        return find_parent(x)->left;
                                }
                                return nullptr;
                        }
                        node <key_t, value_t> *find_parent(node <key_t, value_t> *x) {
                                return x->parent;
                        }
                        node <key_t, value_t> *find_grand_parent(node <key_t, value_t> *x) {
                                if (find_parent(x) != nullptr) {
                                        return find_parent(x)->parent;
                                }
                                return nullptr;
                        }
                        node <key_t, value_t> *find_uncle(node <key_t, value_t> *x) {
                                if (find_grand_parent(x) != nullptr) {
                                        return find_sibling(find_parent(x));
                                }
                                return nullptr;
                        }
                        void fix(node <key_t, value_t> *x) {
                                node <key_t, value_t> *parent = NULL;
                                node <key_t, value_t> *grand_parent = NULL;
                                while ((x != root) && (x->color != black) && (x->parent->color == red)) {
                                        parent = x->parent;
                                        grand_parent = x->parent->parent;
                                        /**
                                         * @brief Case A - Parent of x is left child of the grand parent of x
                                         */
                                        if (parent == grand_parent->left) {
                                                node <key_t, value_t> *uncle = grand_parent->right;
                                                /**
                                                 * @brief Case 1 - The uncle of x is also red. Only recoloring is required
                                                 */
                                                if (uncle != NULL && uncle->color == red) {
                                                        grand_parent->color = red;
                                                        parent->color = black;
                                                        uncle->color = black;
                                                        x = grand_parent;
                                                } else {
                                                        /**
                                                         * @brief Case 2 - x is right child of its parent. Left rotation is required
                                                         */
                                                        if (x == parent->right) {
                                                                left_rotate(parent);
                                                                x = parent;
                                                                parent = x->parent;
                                                        }
                                                        /**
                                                         * @brief Case 3 - x is left child of its parent. Right rotation is required
                                                         */
                                                        right_rotate(grand_parent);
                                                        std::swap(parent->color, grand_parent->color);
                                                        x = parent;
                                                }
                                        } else {
                                                /**
                                                 * @brief Case B - Parent of x is right child of the grand parent of x
                                                 */
                                                node <key_t, value_t> *uncle = grand_parent->left;
                                                /**
                                                 * @brief Case 1 - The uncle of x is also red. Only recoloring required
                                                 */
                                                if ((uncle != NULL) && (uncle->color == red)) {
                                                        grand_parent->color = red;
                                                        parent->color = black;
                                                        uncle->color = black;
                                                        x = grand_parent;
                                                } else {
                                                        /**
                                                         * @brief Case 2 - x is left child of its parent. Right rotation is required
                                                         */
                                                        if (x == parent->left) {
                                                                right_rotate(parent);
                                                                x = parent;
                                                                parent = x->parent;
                                                        }
                                                        /**
                                                         * @brief Case 3 - x is right child of its parent. Left rotation is required
                                                         */
                                                        left_rotate(grand_parent);
                                                        std::swap(parent->color, grand_parent->color);
                                                        x = parent;
                                                }
                                        }
                                }
                                root->color = black;
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
                         * @brief Inserts a new node into the red black tree
                         * @param key The key for the new node
                         * @param value The value for the new node
                         * @return true if the new node was inserted and false otherwise
                         */
                        bool insert(key_t key, value_t value) {
                                node <key_t, value_t> *current = root;
                                node <key_t, value_t> *parent = nullptr;
                                while(current!=nullptr) {
                                        parent = current;
                                        if (key > current->key) {
                                                current = current->right;
                                        } else if (key < current->key) {
                                                current = current->left;
                                        } else {
                                                return false;
                                        }
                                }
                                current = new node <key_t, value_t> (key, value, red);
                                current->parent = parent;
                                if(parent == nullptr) {
                                        root = current;
                                } else if (current->key > parent->key) {
                                        parent->right = current;
                                } else if (current->key < parent->key) {
                                        parent->left = current;
                                }
                                fix(current);
                                return true;
                        }
                        /**
                         * @brief Performs a binary search starting from the root node
                         * @return The node with the key specified
                         */
                        const node <key_t, value_t> *search(key_t key) {
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
                        /**
                         * @brief Finds the node with the minimum key
                         * @return The node with the minimum key
                         */
                        const node <key_t, value_t> *minimum() {
                                node <key_t, value_t> *x = root;
                                if (x == nullptr) return nullptr;
                                while(x->left != nullptr) x = x->left;
                                return x;
                        }
                        /**
                         * @brief Finds the node with the maximum key
                         * @return The node with the maximum key
                         */
                        const node <key_t, value_t> *maximum() {
                                node <key_t, value_t> *x = root;
                                if (x == nullptr) return nullptr;
                                while(x->right != nullptr) x = x->right;
                                return x;
                        }
                        /**
                         * @brief Finds the height of the red black tree
                         * @return The height of the red black tree
                         */
                        unsigned long long height() {
                                return height(root);
                        }
                        /**
                         * @brief Finds the size of the red black tree
                         * @return The size of the red black tree
                         */
                        unsigned long long size() {
                                return size(root);
                        }
                        /**
                         * @brief Finds if the red black tree is empty
                         * @return true if the red black tree is empty and false otherwise
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
