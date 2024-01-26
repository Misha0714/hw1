#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

//constructor 
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

//destructor 
ULListStr::~ULListStr()
{
  clear();
}

//returns that size is 0 if empty 
bool ULListStr::empty() const
{
  return size_ == 0;
}

//returns size of array 
size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
//push new value to the front of the linked list 
void ULListStr::push_front(const std::string& val) {
  
  //first scenario: there is nothing in the array 
  //so we will be the first string at the end of the array and then push front from there 
  if(empty()) { 
      //create a node to store the linked list 
      Item* newp= new Item; 
      //set head and tail to new item 
      head_=newp; 
      tail_=newp;
      //the first index will start at 9     
      newp->first=9; //is there a given variable for the size of this  
      //the last index will point at 10 
      newp->last=10; //val.size()?  
      //the val (parameter) inserted in the first index of val array 
      head_->val[head_->first]=val; 
    }
  //second scenario: there is nothing infront of first index (room in the front)
  else if (head_->first!=0) { //checks to not go out of bounds and nothing ahead of it  
      //the val (parameter) inserted in the index before first index of val array 
      head_->val[head_->first-1]=val; 
      //update where first poitner is pointing to 
      head_->first--;  
    }
  //third scenario: array is full of strings and so need to make a new node 
  else {
      //create new node 
      Item* newp= new Item;
      //make head's prev pointer point to newp 
      head_->prev=newp; 
      //make newp's next pointer pointer to head_ 
      newp->next=head_; 
      //set head to the newp 
      head_ = newp;
      //input first value in last index of array  
      head_->first=9;
      //set last index similar way as first index 
      head_->last=10;
      //set value at first index 
      head_->val[head_->first]=val; 
      //keep updating it for other push fronts 
    }
      size_++; 
}
  

//push new value to the back of the linked list 
void ULListStr::push_back(const std::string& val) {

  //if you are adding list to the back next pointer is changing and the new 
  //int should be pointing to NULL

  //first scenario: if there is nothing in the list 
  //so put first value at the front of the list so you can keep pushing back from there 
  if(empty()) {    
      Item* newp= new Item; 
      //set head and tail to new item 
      head_=newp; 
      tail_=newp;
      //the first index will start at 0     
      newp->first=0;  
      //the last index will point at 1 
      newp->last=1; 
      //the val (parameter) inserted in the first index of val array
      tail_->val[tail_->first]=val; 
  }

  //scenario 2: nothing behind last node --> just insert last  
  else if (tail_->last<10) {   
    //the val (parameter) inserted in the last index 
    tail_->val[tail_->last]=val;
    //update last variable 
    tail_->last++; 
  }
  //third scenario: create new node array is full of strings  
  else {
      //create new node 
      Item* newp= new Item;
      //update prev pointer 
      tail_->next=newp; 
      //update next pointer 
      newp->prev=tail_; 
      //update tail 
      tail_ = newp;
      //set tail_ first index to 0 
      tail_->first=0;
  
      tail_->last=1;
      tail_->val[tail_->first]=val; 
      //keep updating it for other push fronts 
  }
  size_++; 
} 


//delete value in back of linked list 
void ULListStr::pop_back() {

  //When the list is empty 
  if(empty()) {
    return;
  }

  //if amt of strings = 1 
  if(tail_->last - tail_->first == 1) {
    //check if there is only one strings in one node 
    if(head_== tail_) {
      //set pointers to nullptr 
      //deleting head_ will delete tail_ too 
      delete head_;
      head_=NULL; 
      tail_=NULL; 
      size_=0;  
    }
    else {
      //check if there is only one strings in tail but mult. nodes  
      Item* temp=tail_;
      tail_=temp->prev; 
      tail_->next=NULL; 
      delete temp; 
      size_--; 
    }

  }
  else { 
    //just decrement last index if mult. strings 
    tail_->last--; 
    size_--;  

  }
}

//FIX BRACKETS

//delete value in front of linked list 
void ULListStr::pop_front() {

  //When the list is empty 
  if(empty()) {
    return; 
  }
  
  //one string in array of node 
  if(head_->last - head_->first == 1) {
    //one node 
    if(head_==tail_) {
      //set them pointing to null pointer 
      //deleting tail_ will delete head_ too 
      delete tail_; 
      head_=NULL; 
      tail_=NULL;
      size_=0; 
    }
    //mult. nodes
    else {
      Item* temp=head_;
      head_=temp->next; 
      head_->prev=NULL; 
      delete temp; 
      size_--; 
    }  
  }
  else {
    //mult. strings in node just increment first index 
    head_->first++;
    size_--;  
  }

}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  size_t index=loc;
  //create a new node and set to head  
  Item* newp = head_;
  //if the index is greater than the amt of elements in the linked list 
  if(index>=size_) {
    //then return nullptr
    return NULL; 
  }
  //if there is nothing in the new pointer
  while(newp!=NULL) {
    //if loc is greater than index in nodes 
    size_t length = newp->last- newp->first;
    if (index>=length) {
      index-=length;
      newp=newp->next; 
    } 
    else {
      
      return &(newp->val[index+newp->first]);
    }
   
  }

}

//list item that is in the back of the list 
std::string const & ULListStr::back() const{
  
  if(empty()) {
    return "";
  }
  else {
    return tail_->val[tail_->last-1]; 
  }



}
//list item in the front of the list 
std::string const & ULListStr::front() const {

  if(empty()) {
    return "";
  }
  else {
    return head_->val[head_->first]; 
  }

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
