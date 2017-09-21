#include "catch.hpp"
#include <forest/splay_tree.h>

SCENARIO("Test Splay Tree") {
        GIVEN("A Splay Tree") {
                forest::splay_tree::tree <int, int> splay_tree;
                WHEN("The Splay Tree is empty") {
                        THEN("Test empty") {
                                REQUIRE(splay_tree.empty() == true);
                        }
                        THEN("Test size") {
                                REQUIRE(splay_tree.size() == 0);
                        }
                        THEN("Test height") {
                                REQUIRE(splay_tree.height() == 0);
                        }
                        THEN("Test maximum") {
                                auto max = splay_tree.maximum();
                                REQUIRE(max == nullptr);
                        }
                        THEN("Test minimum") {
                                auto min = splay_tree.minimum();
                                REQUIRE(min == nullptr);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = splay_tree.search(555);
                                REQUIRE(result == nullptr);
                        }
                }
                WHEN("The Splay Tree is not empty") {
                        REQUIRE(splay_tree.insert(4 , -10) == true);
                        REQUIRE(splay_tree.insert(2 ,  30) == true);
                        REQUIRE(splay_tree.insert(90, -74) == true);
                        REQUIRE(splay_tree.insert(3 ,   1) == true);
                        REQUIRE(splay_tree.insert(0 ,-110) == true);
                        REQUIRE(splay_tree.insert(14,   0) == true);
                        REQUIRE(splay_tree.insert(45,   0) == true);
                        THEN("Test empty") {
                                REQUIRE(splay_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(splay_tree.size() == 7);
                        }
                        THEN("Test height") {
                                REQUIRE(splay_tree.height() == 5);
                        }
                        THEN("Test maximum") {
                                auto max = splay_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 90);
                                REQUIRE(max->value == -74);
                        }
                        THEN("Test minimum") {
                                auto min = splay_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == -110);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = splay_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = splay_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 1);
                        }
                }
        }
}
