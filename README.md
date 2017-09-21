![forest logo](https://i.imgur.com/zl44kiK.jpg)

Forest is an open source, header-only library of tree data structures written in C++11.

## Installation

#### Linux / macOS
```
$ git clone https://github.com/xorz57/forest.git
$ cd forest
$ mkdir build
$ cd build
$ cmake ..
$ make install
```

## Simple Example

Forest is best explained through examples. The following source code generates a red black tree, inserts 7 nodes and then performs an in order traversal.

```
#include <forest/red_black_tree.h>

int main() {
        // Generate a binary search tree for nodes of integer keys and values
        forest::red_black_tree::tree <int, int> red_black_tree;

        // Insert 7 nodes in the form of a (key, value) pair
        red_black_tree.insert(4,0);
        red_black_tree.insert(2,0);
        red_black_tree.insert(90,0);
        red_black_tree.insert(3,100);
        red_black_tree.insert(0,0);
        red_black_tree.insert(14,0);
        red_black_tree.insert(45,0);

        // Perform an in order traversal
        binary_search_tree.in_order_traversal();

        return 0;
}
```

Refer to the [Quick Start Guide](https://github.com/xorz57/forest/wiki/Quick-Start-Guide) page for further information and examples.
