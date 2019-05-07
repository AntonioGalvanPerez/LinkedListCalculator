 //
//  CalcList
//
//  Created by Antonio Galvan Perez on 9/7/18.
//  Copyright © 2018 Antonio Galvan perez. All rights reserved.
//
#include "CalcList.hpp"
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>


struct node{
    double operand;
    double total;
    FUNCTIONS operation;
    node *next;
    node *prev;
};
int count = 0;
node* head = NULL;
node* tail;


/******************************************Constructor******************************************/
CalcList::CalcList(){
    node* current;
    current = new node;
    current->total = 0.0;
    current->prev = NULL;
    head = current;
    tail = current;
    
}

/***************************************Destructor**********************************************/
CalcList::~CalcList(){
    node *current = head;
    node* next = NULL;
    while(current->prev != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    
    }

/*********************************************Setter**********************************************/
void CalcList::newOperation (const FUNCTIONS func, const double operand){

//Checks if user is attempting to divide by 0
    if(operand == 0 && func == DIVISION){
         throw 99;
        }
//only runs if not dividing by 0
    if((operand != 0 && func == DIVISION) || func == ADDITION || func == SUBTRACTION || func == MULTIPLICATION)
    {
    node* current;
    current = new node;
    current->operation = func;
    current->operand = operand;
    
//check the function and chooses appropriate function
    if (func == ADDITION){
        current->total = (tail->total) + operand;
        count++;
        
    }
    else if (func == SUBTRACTION){
        current->total = (tail->total) - operand;
        count++;
        
    }
    else if (func == MULTIPLICATION){
        current->total = (tail->total) * operand;
        count++;
        
    }
    else if((func == DIVISION) && (operand != 0)){
        current->total= (tail->total) / operand;
        count++;
        }
        
  // Adds new node as the new tail to the linked list
    current->prev = tail;
    tail->next = current;
    tail = current;
    
    }

    }

/*************************Removes last operation and sets new tail*******************************/
void CalcList::removeLastOperation(){

//checks if list is empty
        if(tail->prev == NULL){
            throw 98;
        }
    
//removes tail and changes prev node to be the new tail
    if(tail -> prev != NULL){
    node *current;
    current = new node;
    current = tail->prev;
    current->next = NULL;
    tail = current;
    count--;
    }
    
}




/************************************Returns String with data************************************/
std::string CalcList::toString(unsigned short precision) const{
    
// creats new string and new stringstream (set precision to ss)
    std::string returnString;
    std::stringstream ss;
    ss.precision(precision);
    
//used so the value of count is not changed by function;
    int tempCount = count;
    
// creats new node call current, the data will start at the final node and print in reverse order
    node* current =  tail;
    
//check if the node is the first node in the linked list.
while(current->prev != NULL){
    if (current->operation == ADDITION){
        ss << tempCount;
        ss << ": ";
        ss << std::fixed << ((current->total) -(current->operand));
        ss << "+";
        ss << std::fixed << (current->operand);
        ss << "=";
        ss << std::fixed << (current->total);
        
    }
    else if (current->operation == MULTIPLICATION){
        
        ss << tempCount;
        ss << ": ";
        
        if (current->operand != 0){
            ss << std::fixed << ((current->total) / (current->operand));
        }
        else{
            ss << " " << "0" << " ";
        }
        ss << "*";
        ss << std::fixed << (current->operand);
        ss << "=";
        ss << std::fixed << (current->total);
    }
    else if (current->operation == DIVISION){
        ss << tempCount;
        ss << ": ";
        ss << std::fixed << ((current->total)  * (current->operand));
        ss << "/";
        ss << std::fixed << (current->operand);
        ss << "=";
        ss << std::fixed << (current->total);
    }
    else if (current->operation == SUBTRACTION){
        ss << tempCount;
        ss << ": ";
        ss << std::fixed << ((current->total) + (current->operand));
        ss << "-";
        ss << std::fixed<< (current->operand);
        ss << "=";
        ss << std::fixed << (current->total);
    }
    
    tempCount --;
    ss << "\n";
    current = current->prev;
    }

    returnString = ss.str();
    
    return (returnString);
}

/***************************************Returns Total********************************************/
double CalcList::total() const{
    
    double returnTotal = tail->total;
    return returnTotal;
    
}

