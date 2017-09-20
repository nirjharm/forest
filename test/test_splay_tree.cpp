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
                                int key, value;
                                REQUIRE(splay_tree.maximum(&key, &value) == false);
                        }
                        THEN("Test minimum") {
                                int key, value;
                                REQUIRE(splay_tree.minimum(&key, &value) == false);
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
                                int key, value;
                                REQUIRE(splay_tree.maximum(&key, &value) == true);
                                REQUIRE(key == 90);
                                REQUIRE(value == -74);
                        }
                        THEN("Test minimum") {
                                int key, value;
                                REQUIRE(splay_tree.minimum(&key, &value) == true);
                                REQUIRE(key == 0);
                                REQUIRE(value == -110);
                        }
                }
        }
}
