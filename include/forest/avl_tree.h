#ifndef AVL_TREE_H
#define AVL_TREE_H

namespace forest {
        namespace avl {
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
                        unsigned long long nodes;
                        void pre_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                // process the node n
                                pre_order_traversal(n->left);
                                pre_order_traversal(n->right);
                        }
                        void in_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                in_order_traversal(n->left);
                                // process the node n
                                in_order_traversal(n->right);
                        }
                        void post_order_traversal(node <key_t, value_t> *n) {
                                if (n == nullptr) return;
                                post_order_traversal(n->left);
                                post_order_traversal(n->right);
                                // process the node n
                        }
                public:
                        tree() {
                                root = nullptr;
                                nodes = 0;
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
                };
        }
}

#endif
