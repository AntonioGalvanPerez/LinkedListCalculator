//
//  main.cpp
//  LinkedLinkCalc
//
//  Created by Antonio Galvan perez on 5/5/19.
//  Copyright © 2019 Antonio Galvan Perez. All rights reserved.
//

#include <iostream>
#include "CalcList.hpp"
#include "CalcList.cpp"

int main(int argc, const char * argv[]) {
    CalcList calc;
    int input = 0;
    int number;
    std::cout << "The current total in the calculator is: "<< calc.total() << std::endl << std::endl;

    while (input != 6){
    number = 0;
    std::cout << "What operation would you like to perform?\n\n";
    std::cout << "Enter:\n1: To print current total and operations.\n2: To Add.\n3: To Subtract.\n4: To Divide.\n5: To Remove the last operation.\n6: To quit.\nInput: ";
    std::cin >> input;
    switch (input) {
        case 1:
            std::cin.ignore();
            std::cout<< "What precision would you like to use (Needs to be an integer): ";
            std::cin >> number;
            std::cout<< calc.toString(number)<<std::endl<<std::endl;
            break;
            
        case 2:
            std::cin.ignore();
            std::cout<< "Number to Add: ";
            std::cin >> number;
            calc.newOperation(ADDITION, number);
            break;
            
        case 3:
            std::cin.ignore();
            std::cout<< "Number to Subtract: ";
            std::cin >> number;
            calc.newOperation(SUBTRACTION, number);
            break;
            
        case 4:
            std::cin.ignore();
            std::cout<< "Number to Divide by: ";
            std::cin >> number;
            calc.newOperation(DIVISION, number);
            break;
            
        case 5:
            calc.removeLastOperation();
            break;
            
        default:
            break;
    }
}
            
    return 0;
}
