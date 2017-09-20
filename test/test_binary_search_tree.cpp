#include "catch.hpp"
#include <forest/binary_search_tree.h>

SCENARIO("Test Binary Search Tree") {
        GIVEN("A Binary Search Tree") {
                forest::binary_search_tree::tree <int, int> binary_search_tree;
                WHEN("The Binary Search Tree is empty") {
                        THEN("Test empty") {
                                REQUIRE(binary_search_tree.empty() == true);
                        }
                        THEN("Test size") {
                                REQUIRE(binary_search_tree.size() == 0);
                        }
                        THEN("Test height") {
                                REQUIRE(binary_search_tree.height() == 0);
                        }
                        THEN("Test maximum") {
                                int key, value;
                                REQUIRE(binary_search_tree.maximum(&key, &value) == false);
                        }
                        THEN("Test minimum") {
                                int key, value;
                                REQUIRE(binary_search_tree.minimum(&key, &value) == false);
                        }
                }
                WHEN("The Binary Search Tree is not empty") {
                        REQUIRE(binary_search_tree.insert(4 , -10) == true);
                        REQUIRE(binary_search_tree.insert(2 ,  30) == true);
                        REQUIRE(binary_search_tree.insert(90, -74) == true);
                        REQUIRE(binary_search_tree.insert(3 ,   1) == true);
                        REQUIRE(binary_search_tree.insert(0 ,-110) == true);
                        REQUIRE(binary_search_tree.insert(14,   0) == true);
                        REQUIRE(binary_search_tree.insert(45,   0) == true);
                        THEN("Test empty") {
                                REQUIRE(binary_search_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(binary_search_tree.size() == 7);
                        }
                        THEN("Test height") {
                                REQUIRE(binary_search_tree.height() == 4);
                        }
                        THEN("Test maximum") {
                                int key, value;
                                REQUIRE(binary_search_tree.maximum(&key, &value) == true);
                                REQUIRE(key == 90);
                                REQUIRE(value == -74);
                        }
                        THEN("Test minimum") {
                                int key, value;
                                REQUIRE(binary_search_tree.minimum(&key, &value) == true);
                                REQUIRE(key == 0);
                                REQUIRE(value == -110);
                        }
                }
        }
}
