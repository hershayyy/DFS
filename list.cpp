/**Joshua Yurche
CS319
HW3
list.cpp defines the functions of class List
**/
#include "list.h"

void List::addToEnd(int value){
  node *ptr;
  node *temp;
  for(ptr = head; ptr -> next != tail; ptr = ptr -> next);

  temp = new node;
  temp -> data = value;
  ptr -> next = temp;
  temp -> next = tail;
}

void List::display(){
  node *temp = new node();
  temp = head -> next;

  cout << "list contents: "<< endl;

  if(temp == tail){
    cout<< "this list is empty"<< endl;
    return;
  }
  else{
    do{
      cout<< temp -> data << " : ";
      temp = temp -> next;
    } while(temp != tail);
  }
  cout<<endl;
}

int List::showNeighbor(){
  node *temp = new node();
  temp = head -> next;
  if(temp != tail){
    return temp -> data;
  }
  return 0;
}

void List::killNeighbor(){
  node *curr;
  node * temp;
  curr = head -> next;

  if(head -> next != tail){
    temp = curr;
    curr = curr -> next;
    delete temp;
    head -> next = curr;
  }
}

int List::size()
{
  int count = 0;
  node *temp = head;
  while(temp -> next != tail){
      count++;
      temp = temp -> next;
    }
  return count;
}
