#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <forest/avl_tree.h>

SCENARIO("Test AVL Tree") {
  GIVEN("An AVL Tree") {
    forest::avl_tree <int, int> avl_tree;
    WHEN("The AVL Tree is empty") {
      THEN("Test empty") {
        REQUIRE(avl_tree.empty() == true);
      }
      THEN("Test size") {
        REQUIRE(avl_tree.size() == 0);
      }
      THEN("Test height") {
        REQUIRE(avl_tree.height() == 0);
      }
      THEN("Test maximum") {
        auto max = avl_tree.maximum();
        REQUIRE(max == nullptr);
      }
      THEN("Test minimum") {
        auto min = avl_tree.minimum();
        REQUIRE(min == nullptr);
      }
      THEN("Test predecessor for a node that does not exist") {
        auto predecessor = avl_tree.predecessor(1911);
        REQUIRE(predecessor == nullptr);
      }
      THEN("Test successor for a node that does not exist") {
        auto successor = avl_tree.successor(1337);
        REQUIRE(successor == nullptr);
      }
      THEN("Test search for a node that does not exist") {
        auto result = avl_tree.search(555);
        REQUIRE(result == nullptr);
      }
    }
    WHEN("Nodes are inserted in random order") {
      avl_tree.insert(4 , 0);
      avl_tree.insert(2 , 0);
      avl_tree.insert(90, 0);
      avl_tree.insert(3 , 0);
      avl_tree.insert(0 , 0);
      avl_tree.insert(14, 0);
      avl_tree.insert(45, 0);
      THEN("Test empty") {
        REQUIRE(avl_tree.empty() == false);
      }
      THEN("Test size") {
        REQUIRE(avl_tree.size() == 7);
      }
      THEN("Test height") {
        REQUIRE(avl_tree.height() == 3);
      }
      THEN("Test maximum") {
        auto max = avl_tree.maximum();
        REQUIRE(max != nullptr);
        REQUIRE(max->key == 90);
      }
      THEN("Test minimum") {
        auto min = avl_tree.minimum();
        REQUIRE(min != nullptr);
        REQUIRE(min->key == 0);
      }
      THEN("Test predecessor for a node that does exist") {
        auto predecessor = avl_tree.predecessor(90);
        REQUIRE(predecessor != nullptr);
        REQUIRE(predecessor->key == 45);
      }
      THEN("Test successor for a node that does exist") {
        auto successor = avl_tree.successor(0);
        REQUIRE(successor != nullptr);
        REQUIRE(successor->key == 2);
      }
      THEN("Test predecessor for a node that does not exist") {
        auto predecessor = avl_tree.predecessor(1917);
        REQUIRE(predecessor == nullptr);
      }
      THEN("Test successor for a node that does not exist") {
        auto successor = avl_tree.successor(1920);
        REQUIRE(successor == nullptr);
      }
      THEN("Test search for a node that does not exist") {
        auto result = avl_tree.search(1337);
        REQUIRE(result == nullptr);
      }
      THEN("Test search for a node that does exist") {
        auto result = avl_tree.search(3);
        REQUIRE(result != nullptr);
        REQUIRE(result->key == 3);
      }
    }
    WHEN("Nodes are inserted in ascending order") {
      for (int i = 0; i < 10; i++) {
        avl_tree.insert(i, 0);
      }
      THEN("Test empty") {
        REQUIRE(avl_tree.empty() == false);
      }
      THEN("Test size") {
        REQUIRE(avl_tree.size() == 10);
      }
      THEN("Test height") {
        REQUIRE(avl_tree.height() == 4);
      }
      THEN("Test maximum") {
        auto max = avl_tree.maximum();
        REQUIRE(max != nullptr);
        REQUIRE(max->key == 9);
      }
      THEN("Test minimum") {
        auto min = avl_tree.minimum();
        REQUIRE(min != nullptr);
        REQUIRE(min->key == 0);
      }
      THEN("Test predecessor for a node that does exist") {
        auto predecessor = avl_tree.predecessor(9);
        REQUIRE(predecessor != nullptr);
        REQUIRE(predecessor->key == 8);
      }
      THEN("Test successor for a node that does exist") {
        auto successor = avl_tree.successor(3);
        REQUIRE(successor != nullptr);
        REQUIRE(successor->key == 4);
      }
      THEN("Test predecessor for a node that does not exist") {
        auto predecessor = avl_tree.predecessor(1917);
        REQUIRE(predecessor == nullptr);
      }
      THEN("Test successor for a node that does not exist") {
        auto successor = avl_tree.successor(1920);
        REQUIRE(successor == nullptr);
      }
      THEN("Test search for a node that does not exist") {
        auto result = avl_tree.search(1337);
        REQUIRE(result == nullptr);
      }
      THEN("Test search for a node that does exist") {
        auto result = avl_tree.search(3);
        REQUIRE(result != nullptr);
        REQUIRE(result->key == 3);
      }
    }
    WHEN("Nodes are inserted in descending order") {
      for (int i = 9; i >= 0; i--) {
        avl_tree.insert(i, 0);
      }
      THEN("Test empty") {
        REQUIRE(avl_tree.empty() == false);
      }
      THEN("Test size") {
        REQUIRE(avl_tree.size() == 10);
      }
      THEN("Test height") {
        REQUIRE(avl_tree.height() == 4);
      }
      THEN("Test maximum") {
        auto max = avl_tree.maximum();
        REQUIRE(max != nullptr);
        REQUIRE(max->key == 9);
      }
      THEN("Test minimum") {
        auto min = avl_tree.minimum();
        REQUIRE(min != nullptr);
        REQUIRE(min->key == 0);
      }
      THEN("Test predecessor for a node that does exist") {
        auto predecessor = avl_tree.predecessor(9);
        REQUIRE(predecessor != nullptr);
        REQUIRE(predecessor->key == 8);
      }
      THEN("Test successor for a node that does exist") {
        auto successor = avl_tree.successor(3);
        REQUIRE(successor != nullptr);
        REQUIRE(successor->key == 4);
      }
      THEN("Test predecessor for a node that does not exist") {
        auto predecessor = avl_tree.predecessor(1917);
        REQUIRE(predecessor == nullptr);
      }
      THEN("Test successor for a node that does not exist") {
        auto successor = avl_tree.successor(1920);
        REQUIRE(successor == nullptr);
      }
      THEN("Test search for a node that does not exist") {
        auto result = avl_tree.search(1337);
        REQUIRE(result == nullptr);
      }
      THEN("Test search for a node that does exist") {
        auto result = avl_tree.search(3);
        REQUIRE(result != nullptr);
        REQUIRE(result->key == 3);
      }
    }
  }
}
