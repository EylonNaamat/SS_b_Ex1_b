#include <iostream>
#include "mat.hpp"
#include <string>
#include <vector>


int main(){
    int row, col = 0;
    char symbol_1, symbol_2 = 0;
    std::string ans;
    int num = 0;
    std::cout << "enter a number of checks" << std::endl;
    std::cin >> num;
    for(int i = 0; i < num; ++i){
        std:: cout << "insert a number of column" << std::endl;
        std::cin >> col;
        std:: cout << "insert a number of row" << std::endl;
        std::cin >> row;
        std::cout << "insert first symbol" << std::endl;
        std::cin >> symbol_1;
        std::cout << "insert second symbol" << std::endl;
        std::cin >> symbol_2;
        ans = ariel::mat(col, row, symbol_1, symbol_2);
        std::cout << ans << std::endl;
    }
    return 0;
}