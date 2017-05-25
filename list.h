/**Joshua Yurche
CS319
HW3
list.h defines a list class which is used in an array based list
to implement the DFS algorithm
**/
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

//List node structure
struct node{
  int data;
  node *next;
};

//Class for a list
class List{
public:
  //constructor for a new empty list with a head and tail node
  List(): head(0), tail(0){
    head = new node;
    tail = new node;
    head -> next = tail;
  };
  void display();
  int showNeighbor();
  void killNeighbor();
  void addToEnd(int value);
  int size();

private:
  //pointer of the head node
  node *head;
  //pointer of the tail node
  node *tail;
};

#endif
