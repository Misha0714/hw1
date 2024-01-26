/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
  //setting nodes 
  Node n6(6, nullptr); 
  Node n5(5, &n6);
  Node n4(4, &n5); 
  Node n3(3, &n4);
  Node n2(2, &n3);
  Node n1(1, &n2);

  Node *in= &n1; 
  Node *odds = nullptr;
  Node *evens = nullptr; 

  split(in, odds, evens); 

  //print evens 
  std::cout << "evens list"<<std::endl;  
  Node *cnt = evens; 
  while (cnt!=nullptr) {
    std::cout << cnt->value << std::endl; 
    cnt = cnt->next; 
  }

  //print odds 
  std::cout << "odds list"<<std::endl;  
  cnt = odds; 
  while (cnt!=nullptr) {
    std::cout << cnt->value<<std::endl; 
    cnt = cnt->next; 
  }
   

}
