#include "catch.hpp"
#include <forest/red_black_tree.h>

SCENARIO("Test Red Black Tree") {
        GIVEN("A Red Black Tree") {
                forest::red_black_tree::tree <int, int> red_black_tree;
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
                WHEN("The Red Black Tree is not empty") {
                        REQUIRE(red_black_tree.insert(4 , -10) == true);
                        REQUIRE(red_black_tree.insert(2 ,  30) == true);
                        REQUIRE(red_black_tree.insert(90, -74) == true);
                        REQUIRE(red_black_tree.insert(3 ,   1) == true);
                        REQUIRE(red_black_tree.insert(0 ,-110) == true);
                        REQUIRE(red_black_tree.insert(14,   0) == true);
                        REQUIRE(red_black_tree.insert(45,   0) == true);
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
        }
}
