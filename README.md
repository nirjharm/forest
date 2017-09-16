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
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]) {
        srand(time(0));

        forest::splay::tree <int, int> splay_tree;

        for (size_t i = 0; i < 10; i++) {
                splay_tree.insert(rand()%10000, 0);
        }

        splay_tree.in_order_traversal();

        return 0;
}
```
