/**
 *
 * AUTHORS: <Guy Cohen>
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
#include <string>
using namespace std;

const unsigned int MAX_NUM = 1000000;

Board board;
TEST_CASE("Post and Read check") {
    board.post(0,0,Direction::Horizontal,"xyz");
    CHECK(board.read(0,0,Direction::Horizontal,3) == "xyz");
    
    board.post(3,7,Direction::Horizontal,"amn");
    CHECK(board.read(3,7,Direction::Horizontal,3) == "amn");
       
    board.post(11,0,Direction::Horizontal,"my name is:");
    CHECK(board.read(11,0,Direction::Horizontal,11) == "my name is:");
    
    board.post(11,13,Direction::Horizontal,"Guy");
    CHECK(board.read(11,0,Direction::Horizontal,16) == "my name is:__Guy");

    board.post(12,1,Direction::Horizontal,"aaa");
    CHECK(board.read(12,0,Direction::Horizontal,4) == "_aaa");
    
    board.post(12,2,Direction::Horizontal,"bbb");
    CHECK(board.read(12,0,Direction::Horizontal,5) == "_abbb");
       
    board.post(2,6,Direction::Horizontal,"Ert");
    CHECK(board.read(2,8,Direction::Horizontal,3) == "t__");
    
    board.post(2,6,Direction::Horizontal,"Err");
    CHECK(board.read(2,6,Direction::Horizontal,3) == "Err");

    board.post(3,1,Direction::Horizontal,"xyz");
    CHECK(board.read(3,0,Direction::Horizontal,5) == "_xyz_");
    
    board.post(4,4,Direction::Horizontal,"Testing");
    CHECK(board.read(4,0,Direction::Horizontal,14) == "____Testing___");
       
    board.post(5,4,Direction::Horizontal,"Testing");
    CHECK(board.read(4,4,Direction::Vertical,2) == "TT");
    
    board.post(6,4,Direction::Horizontal,"Testing");
    CHECK(board.read(4,5,Direction::Vertical,3) == "eee");

    board.post(4,11,Direction::Vertical,"!!!");
    CHECK(board.read(4,4,Direction::Horizontal,8) == "Testing!");
    CHECK(board.read(5,4,Direction::Horizontal,8) == "Testing!");
    CHECK(board.read(6,4,Direction::Horizontal,8) == "Testing!");
    
    board.post(14,0,Direction::Vertical,"Testing!");
    CHECK(board.read(14,0,Direction::Vertical,8) == "Testing!");
       
    board.post(14,1,Direction::Horizontal,"esting!");
    CHECK(board.read(14,0,Direction::Horizontal,8) == "Testing!");
    
    board.post(0,10,Direction::Horizontal,"c++");
    CHECK(board.read(0,10,Direction::Horizontal,1) == "c");
    CHECK(board.read(0,11,Direction::Horizontal,1) == "+");
    CHECK(board.read(0,12,Direction::Horizontal,1) == "+");
    CHECK(board.read(0,10,Direction::Horizontal,3) == "c++");

    board.post(0,0,Direction::Horizontal,"xyz");
    CHECK(board.read(100,10,Direction::Horizontal,3) == "___");
    
    board.post(23,0,Direction::Horizontal,"xyz");
    CHECK(board.read(23,0,Direction::Horizontal,5) == "xyz__");
       
    board.post(22,2,Direction::Vertical,"Ex2");
    CHECK(board.read(22,2,Direction::Horizontal,3) == "E__");
    CHECK(board.read(23,2,Direction::Horizontal,3) == "x__");
    CHECK(board.read(24,2,Direction::Horizontal,3) == "2__");
    CHECK(board.read(22,2,Direction::Vertical,3) == "Ex2");
    
    board.post(22,3,Direction::Horizontal,"x2!");
    board.post(23,3,Direction::Horizontal,"x2!");
    board.post(24,3,Direction::Horizontal,"x2!");
    CHECK(board.read(22,2,Direction::Horizontal,4) == "Ex2!");
    CHECK(board.read(23,2,Direction::Horizontal,4) == "xx2!");
    CHECK(board.read(24,2,Direction::Horizontal,4) == "2x2!");
    CHECK(board.read(25,2,Direction::Horizontal,4) == "____");
}

TEST_CASE("Out of the board bounds") {
    CHECK_THROWS(board.post(MAX_NUM-2,3,Direction::Vertical,"aaa"));
    CHECK_THROWS(board.post(1,MAX_NUM-2,Direction::Horizontal,"axa"));
    CHECK_THROWS(board.post(MAX_NUM-2,3,Direction::Vertical,"ababcd"));
}