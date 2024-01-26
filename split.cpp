/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream> 

/* Add a prototype for a helper function here if you need */

//Node*&in is reference to pointer to inputted linked list 
//Node*&in is reference to pointer to odd linked list 
//Node*&in is reference to pointer to even linked list 
void split(Node*& in, Node*& odds, Node*& evens)  {

  //if there is nothing in the linked list 
  if(in==nullptr) {
    in=nullptr;
    return;  
  }
  //call recursive function here 
  split(in->next, odds, evens);

  //if value is even 
  if((in->value)%2==0) { 
    //std::cout << "Value: " + (*in).value << std::endl; 
    //if there is nothing in the evens list 
    if(evens==nullptr) {
      //insert first value that is even in "in" in evens
      evens=in;
    }
    else {
      //if it is not null then insert it in evens next 
      in->next=evens; 
      //update evens pointer to point at next node 
      evens=in; 
    }
      //now working with evenptr directly
      //next time something is inputted to evensptr it will be in the next position 
  }
  else if ((in->value)%2!=0) {
    if(odds==nullptr) {
      odds=in; 
    }
    else {
      in->next=odds; 
      odds=in; 
    }

  } 
  
  in=nullptr;
  delete in; 
   
  
  //end  
}

/* If you needed a helper function, write it here */
