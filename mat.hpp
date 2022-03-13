#include <iostream>
#include <string>
#include <vector>

namespace ariel{ 
    std::string mat(int col, int row, char symbol_1, char symbol_2);
    void fill_mat(std::vector<std::vector<char>> *mat, int col, int row, char symbol_1, char symbol_2);
    std::string convert_mat(std::vector<std::vector<char>> *mat, int col, int row);
    void check_input(int col, int row, char symbol_1, char symbol_2);
}