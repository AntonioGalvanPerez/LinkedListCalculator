//
//  CalcList.hpp
//  CalcList
//
//  Created by Antonio Galvan Perez on 9/7/18.
//  Copyright © 2018 Antonio Galvan perez. All rights reserved.
//


#ifndef CalcList_hpp
#define CalcList_hpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "CalcListInterface.hpp"
// Moved Enum to hpp file so other could use.

class CalcList{
public:
//counter
    //int count = 0;
/***************************************Constructor***********************************************/
    CalcList();
/***************************************Destructor************************************************/
    ~CalcList();
/*********************************************Setter**********************************************/
    void newOperation (const FUNCTIONS func, const double operand);
    void removeLastOperation();
    std::string toString(unsigned short precision) const;
/*********************************************Getter**********************************************/
    double total() const;
private:
    
};



#endif /* CalcList_h */
