/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;




TEST_CASE("Good post") {
    //Prepare board & post
    Board board;
    CHECK(board.read(/*row=*/5000, /*column=*/5000, Direction::Vertical, /*length=*/3) == "___");
    CHECK(board.read(/*row=*/5000, /*column=*/5000, Direction::Horizontal, /*length=*/3) == "___");
    uint row = (uint)rand();
    uint col = (uint)rand();
    //Random pos
    CHECK(board.read(/*row=*/row, /*column=*/col, Direction::Horizontal, /*length=*/1) == "_");

    //Generate random word, post it then read it.
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
    'r','s','t','u','v','w','x',
    'y','z'};
    string ran = "";
    //uint n = (uint)rand() % row;
    for (int i=0;i<10;i++) {
        ran=ran + letters[rand() % 26];
    }
    board.post(/*row=*/row, /*column=*/col, Direction::Horizontal, ran);
    CHECK(board.read(/*row=*/row, /*column=*/col, Direction::Horizontal, /*length=*/10) == ran);

    //Post specific word
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");


    //Check vertical vs horizontal
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) == "_b_");
    CHECK(board.read(/*row=*/100, /*column=*/201, Direction::Vertical, /*length=*/3) == "b__");
    CHECK(board.read(/*row=*/100 ,/*column=*/201, Direction::Horizontal, /*length=*/4) == "bcd_");
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Horizontal, /*length=*/3) == "___");

    //Check diff lengths
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/28) == "_b__________________________");
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/1) == "_");

    //Overwrite an existing post
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "xyzw");
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) == "_y_");
    CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/4) == "xyzw");
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abzw");
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) == "_b_");
    CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/4) == "abzw");
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "____");
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) == "___");
    CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/4) == "____");
    board.post(/*row=*/101, /*column=*/200, Direction::Vertical, "oh");
    CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Vertical, /*length=*/3) == "_oh");
    CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/4) == "____");
    board.post(/*row=*/105, /*column=*/200, Direction::Vertical, "ho");
    CHECK(board.read(/*row=*/106, /*column=*/200, Direction::Vertical, /*length=*/3) == "o__");
    CHECK(board.read(/*row=*/106, /*column=*/200, Direction::Horizontal, /*length=*/3) == "o__");

    //Border
    board.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "rps");
    CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/3) == "r__");

}




