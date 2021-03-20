#include<iostream>
#include<string>
#include<array>
#include "Board.hpp"
using namespace ariel;
using namespace std;
using ariel::Direction;

const char EMPTY = '_';
const unsigned int MAX_NUM = 1000000;

unsigned int r = 0;
unsigned int c = 0;
unsigned int notice_size = 0;
string clean = "_";
namespace ariel{
    Board:: Board(){
        row_size = 1;
        col_size = 1;
        board.resize(row_size,vector<char>(col_size, EMPTY));
    }
    void Board::post(unsigned int row, unsigned int col, Direction shape, string const & notice){
        unsigned long int out_of_bounds = 0;
        notice_size = notice.size();
        out_of_bounds = row + notice_size;
        if(out_of_bounds > MAX_NUM){
            std:: cout << out_of_bounds;
            throw std::exception();
        }
        out_of_bounds = col + notice_size;
        if(out_of_bounds > MAX_NUM){
            std:: cout << out_of_bounds;
            throw std::exception();
        }


        if(shape == Direction::Vertical){
            r = row + notice_size + 1;
            if(row_size < r){
            row_size = r;
            }
            board.resize(r, vector<char>(col + 4,EMPTY));
            c = col + 4;
            col_size = col;
            /*for(uint i=0;i<board.size();i++){
                board[i].resize(c,EMPTY);
            }*/
        }
        else{
            r = row + 4;
            board.resize(r, vector<char>(col + notice_size + 4,EMPTY));
            c = col + notice_size + 4;
            if(col_size<c){
                col_size = c;
            }
            if(row_size < r){
            row_size = r;
            }
            col_size = col;
            for(uint i=0;i<board.size();i++){
            board[i].resize(c,EMPTY);
            }
        }
        if(shape == Direction::Horizontal){
            unsigned int i = 0;
            for(char dig : notice){
                board[row][col + i] = dig;
                i++;
            }
        }
        else{
            unsigned int i = 0;
            for(char dig : notice){
                board[row + i][col] = dig;
                i++;
            }
        }
    }
    string Board::read(unsigned int row, unsigned int col, Direction shape, unsigned int lenght){
        unsigned long int out_of_bounds = 0;
        out_of_bounds = row + lenght;
        if(out_of_bounds > MAX_NUM){
            throw std::exception();
        }
        out_of_bounds = col + lenght;
        if(out_of_bounds > MAX_NUM){
            throw std::exception();
        }

        unsigned int len = 0;
        unsigned int r = row;
        unsigned int c = col;
        unsigned int index = 0;
        std::string str;
        
        if(shape == Direction:: Horizontal){
            r = row +1;
            c = col + lenght + 2;
            if(board.size() < r){
                board.resize(r, vector<char>(c,EMPTY));
                row_size = r;
                col_size = c;
            }
            if(board[row].size()<c){
                board[row].resize(c,EMPTY);
            }
        }
        else{
            r = row + lenght + 2;
            c = col + 1;
            board.resize(r, vector<char>(c,EMPTY));
            row_size = r;
            col_size = c;
        }
        r = row;
        c = col;
        str.reserve(lenght);
        while (lenght>len){
            str += board[r][c];
            if(shape == Direction::Horizontal){
                c++;
                len++;
                index++;
            }
            else{
                r++;
                len++;
                index++;
            }

        }
        return str;
    }
    void Board::show(){
        for(uint i=0;i<board.size();i++){
            cout << i << ": ";
            for(uint j=0;j<=board[i].size();j++){
                cout << board[i][j];
            }
            cout << endl;
        }
    }


}

