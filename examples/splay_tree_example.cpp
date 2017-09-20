#include <forest/splay_tree.h>
#include <iostream>

int main(int argc, char const *argv[]) {
        forest::splay_tree::tree <int, int> splay_tree;

        splay_tree.insert(4,0);
        splay_tree.insert(2,0);
        splay_tree.insert(90,0);
        splay_tree.insert(3,100);
        splay_tree.insert(0,0);
        splay_tree.insert(14,0);
        splay_tree.insert(45,0);

        std::cout << "Pre Order Traversal" << std::endl;
        std::cout << std::endl;
        splay_tree.pre_order_traversal();
        std::cout << std::endl;

        std::cout << "In Order Traversal" << std::endl;
        std::cout << std::endl;
        splay_tree.in_order_traversal();
        std::cout << std::endl;

        std::cout << "Post Order Traversal" << std::endl;
        std::cout << std::endl;
        splay_tree.post_order_traversal();
        std::cout << std::endl;

        std::cout << "Breadth First Traversal" << std::endl;
        std::cout << std::endl;
        splay_tree.breadth_first_traversal();
        std::cout << std::endl;

        int key, value;

        splay_tree.minimum(&key, &value);
        std::cout << "minimum: (" << key << ", " << value << ")" << std::endl;

        splay_tree.maximum(&key, &value);
        std::cout << "maximum: (" << key << ", " << value << ")" << std::endl;

        std::cout << "height: " << splay_tree.height() << std::endl;
        std::cout << "size: " << splay_tree.size() << std::endl;
	std::cout << "empty: " << (splay_tree.empty() ? "yes" : "no") << std::endl;

        return 0;
}
