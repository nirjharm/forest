![forest logo](https://i.imgur.com/zl44kiK.jpg)

forest is an open source library of tree data structures written in C++11.

Using the forest library is really easy
```
#include <forest/splay_tree.h>
```

Specifying the include path is also very easy
```
g++ main.cpp -I forest/include -std=c++11
```

```
#include <forest/splay_tree.h>

int main(int argc, char const *argv[]) {
        forest::splay_tree::tree <int, int> splay_tree;

        splay_tree.insert(4, -32);
        splay_tree.insert(2, 12);
        splay_tree.insert(90, -2);
        splay_tree.insert(3, -12);
        splay_tree.insert(0, 22);
        splay_tree.insert(14, 23);
        splay_tree.insert(45, 22);

        splay_tree.in_order_traversal();

        return 0;
}
```
