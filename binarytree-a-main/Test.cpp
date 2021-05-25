#include "doctest.h"
#include <iostream>
#include <string>
#include "BinaryTree.hpp"



using namespace std;
using namespace ariel;

TEST_CASE("char tree check") {
    BinaryTree<char> chars;
    chars.add_root('1');
    CHECK_NOTHROW(chars.add_left('1', '2'));
    CHECK_NOTHROW(chars.add_right('1', '3'));
    CHECK_THROWS(chars.add_left('7', '5'));
    CHECK_NOTHROW(chars.add_left('1', '7'));
    CHECK_NOTHROW(chars.add_right('7', '5'));
   
}


TEST_CASE("string tree check") {
    BinaryTree<string> str;
    str.add_root("1");
    CHECK_NOTHROW(str.add_left("1", "2"));
    CHECK_NOTHROW(str.add_right("1", "3"));
    CHECK_THROWS(str.add_left("7", "5"));
    CHECK_NOTHROW(str.add_left("1", "7"));
    CHECK_NOTHROW(str.add_right("7", "5"));
   
}



TEST_CASE("int tree check") {
    BinaryTree<int> ints;
    ints.add_root(1);
    CHECK_NOTHROW(ints.add_left(1, 2));
    CHECK_NOTHROW(ints.add_right(1, 3));
    CHECK_THROWS(ints.add_left(7, 5));
    CHECK_NOTHROW(ints.add_left(1, 7));
    CHECK_NOTHROW(ints.add_right(7, 5));
   
}

TEST_CASE("double tree check") {
    BinaryTree<double> doubles;
    doubles.add_root(1.2);
    CHECK_NOTHROW(doubles.add_left(1.2, 2.5));
    CHECK_NOTHROW(doubles.add_right(1.2, 3.7));
    CHECK_THROWS(doubles.add_left(7.0, 5.6));
    CHECK_NOTHROW(doubles.add_left(1.2, 7.0));
    CHECK_NOTHROW(doubles.add_right(7.0, 5.6));
   
}

