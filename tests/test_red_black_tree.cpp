#include "catch.hpp"
#include <forest/red_black_tree.h>

SCENARIO("Test Red Black Tree") {
        GIVEN("A Red Black Tree") {
                forest::red_black_tree <int, int> red_black_tree;
                WHEN("The Red Black Tree is empty") {
                        THEN("Test empty") {
                                REQUIRE(red_black_tree.empty() == true);
                        }
                        THEN("Test size") {
                                REQUIRE(red_black_tree.size() == 0);
                        }
                        THEN("Test height") {
                                REQUIRE(red_black_tree.height() == 0);
                        }
                        THEN("Test maximum") {
                                auto max = red_black_tree.maximum();
                                REQUIRE(max == nullptr);
                        }
                        THEN("Test minimum") {
                                auto min = red_black_tree.minimum();
                                REQUIRE(min == nullptr);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = red_black_tree.search(555);
                                REQUIRE(result == nullptr);
                        }
                }
                WHEN("Nodes are inserted in random order") {
                        REQUIRE(red_black_tree.insert(4 , -10) != nullptr);
                        REQUIRE(red_black_tree.insert(2 ,  30) != nullptr);
                        REQUIRE(red_black_tree.insert(90, -74) != nullptr);
                        REQUIRE(red_black_tree.insert(3 ,   1) != nullptr);
                        REQUIRE(red_black_tree.insert(0 ,-110) != nullptr);
                        REQUIRE(red_black_tree.insert(14,   0) != nullptr);
                        REQUIRE(red_black_tree.insert(45,   0) != nullptr);
                        THEN("Test empty") {
                                REQUIRE(red_black_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(red_black_tree.size() == 7);
                        }
                        THEN("Test height") {
                                REQUIRE(red_black_tree.height() == 3);
                        }
                        THEN("Test maximum") {
                                auto max = red_black_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 90);
                                REQUIRE(max->value == -74);
                        }
                        THEN("Test minimum") {
                                auto min = red_black_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == -110);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = red_black_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = red_black_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 1);
                        }
                }
                WHEN("Nodes are inserted in ascending order") {
                        for (int i = 0; i < 10; i++) {
                                REQUIRE(red_black_tree.insert(i, i*i) != nullptr);
                        }
                        THEN("Test empty") {
                                REQUIRE(red_black_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(red_black_tree.size() == 10);
                        }
                        THEN("Test height") {
                                REQUIRE(red_black_tree.height() == 5);
                        }
                        THEN("Test maximum") {
                                auto max = red_black_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 9);
                                REQUIRE(max->value == 81);
                        }
                        THEN("Test minimum") {
                                auto min = red_black_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == 0);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = red_black_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = red_black_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 9);
                        }
                }
                WHEN("Nodes are inserted in descending order") {
                        for (int i = 9; i >= 0; i--) {
                                REQUIRE(red_black_tree.insert(i, i*i) != nullptr);
                        }
                        THEN("Test empty") {
                                REQUIRE(red_black_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(red_black_tree.size() == 10);
                        }
                        THEN("Test height") {
                                REQUIRE(red_black_tree.height() == 5);
                        }
                        THEN("Test maximum") {
                                auto max = red_black_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 9);
                                REQUIRE(max->value == 81);
                        }
                        THEN("Test minimum") {
                                auto min = red_black_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == 0);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = red_black_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = red_black_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 9);
                        }
                }
        }
}
