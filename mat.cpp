#include <iostream>
#include <string>
#include "mat.hpp"
#include <stdexcept>
#include <vector>


/***
 * this function checks if the input is good, it checks if the 
 * number of columns or the number of rows is even - if so 
 * the function throws an invalid argument exception.
 * if the symbols are tab, enter, space, carriage return character the function throws an exception
 * if the number of columns or the number of rows is non positive the function throws an exception
 * if the ascii number of the symbols is under 33 or over 126 the function throws an exeption, 
 * because those symbols are illegal.
 * ***/
void ariel::check_input(int col, int row, char symbol_1, char symbol_2){
    const int bott_char = 33;
    const int top_char = 126;
    if (col % 2 == 0 || row % 2 == 0){
        throw std::invalid_argument("Mat size is always odd");
    }
    if (symbol_1 == ' ' || symbol_1 == '\t' || symbol_1 == '\n' || symbol_1 == '\r'){
        throw std::invalid_argument("invalid symbol");
    }
    if (symbol_2 == ' ' || symbol_2 == '\t' || symbol_2 == '\n' || symbol_2 == '\r'){
        throw std::invalid_argument("invalid symbol");
    }
    if(row < 0 || col < 0){
        throw std::invalid_argument("you should only positive numbers");
    }
    if(symbol_1 < bott_char || symbol_1 > top_char){
        throw std::invalid_argument("not a good char");
    }
    if(symbol_2 < bott_char || symbol_2 > top_char){
        throw std::invalid_argument("not a good char");
    }
}

/***
 * this is the main function, this function gets a number of columns, number of rows
 * first symbol, and second symbol and prints a mat.
 * first we check if the input is good
 * if so, we create a new matrix and fill it, 
 * then converts the matrix into a string and return the string
 * ***/
std::string ariel::mat(int col, int row, char symbol_1, char symbol_2){
    check_input(col, row, symbol_1, symbol_2);
    std::string ans;
    std::vector < std::vector<char>> mat(row, std::vector<char>(col));
    fill_mat(&mat, col, row, symbol_1, symbol_2);
    ans = convert_mat(&mat, col, row);
    return ans;
}

/***
 * this function gets a pointer to a matrix, number of columns, number of rows,
 * first symbol, and a second symbol, and fills the matrix as a mat
 * ***/
void ariel::fill_mat(std::vector<std::vector<char>> *mat, int col, int row, char symbol_1, char symbol_2){
    // defining boundries to the matrix
    int top = 0;
    int down = row-1;
    int left = 0;
    int right = col-1;
    // defining a flag to check if we should switch symbols
    int flag = 0;
    // a variable that holds the current symbol
    char curr_symbol = symbol_1;
    // we run in a loop until one of the boundries get past each other
    while(top <= down && left <= right){
        // a check to determine what is the current symbol
        if(flag % 2 == 0){
            curr_symbol = symbol_1;
        }else{
            curr_symbol = symbol_2;
        }
        // filling the first row of the matrix and then incrementing the top boundry by 1
        for(int i = left; i <= right; ++i){
            (*mat)[top][i] = curr_symbol;
        }
        ++top;
        // filling the right column of the matrix and then decreasing the right boundry by 1
        for(int i = top; i <= down; ++i){
            (*mat)[i][right] = curr_symbol;
        }
        --right;
        // filling the bottom row of the matrix and then decreasing the bottom boundry by 1
        for(int i = right; i >= left; --i){
            (*mat)[down][i] = curr_symbol;
        }
        --down;
        // filling the left column of the matrix and then incrementing the left boundry by 1
        for(int i = down; i >= top; --i){
            (*mat)[i][left] = curr_symbol;
        }
        ++left;
        // incrementing the flag by 1, so we can alternate the symbols
        ++flag;
    }
}

/***
 * this function gets a pointer to a matrix, number of columns and a number of rows
 * and return a string representing that matrix
 * ***/
std::string ariel::convert_mat(std::vector<std::vector<char>> *mat, int col, int row){
    std::string ans;
    // running on the matrix and appending each character to ans
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            ans += (*mat)[i][j];
        }
        // after each row appending an "enter" in order to kepp the form of a matrix
        ans += "\n";
    }
    return ans;
}




