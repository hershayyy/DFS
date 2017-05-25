/**Joshua Yurche
CS319
HW3
main.cpp reads in a csv text file and puts the values into an
array based list which is then used to implement the DFS algorithm.
**/
#include "list.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stack>
#include <list>

using namespace std;

int main(){

  //FIND LENGTH OF ARRAY
  fstream file("adj.txt");
  vector<string> mlength;
  string line;

  int vertCount = 0;
  while(file && getline(file, line))
  {
      string data;
      stringstream ss(line);
      while(ss && ss >> data)
      {
          mlength.push_back(data);
      }
      ++vertCount;
  }
  //cout << "length is "<< vertCount << endl;


//READ IN VALUES FROM CSV TEXT FILE CONTAINING AN ADJACENCY
//MATRIX OF A DIRECTED GRAPH. SEPERATE VALUES FROM COMMAS.
//IF VALUE IS 1, ADD THE neighbor VERTEX NUMBER OF THAT COLUMN TO
//THE LINKED LIST CONTAINED IN THE graph[vertex] ARRAY
  vector<string> v_input;
  List graph[vertCount];
  ifstream getdata("adj.txt");

  string s;
  while(getline(getdata, s, ',')){
    v_input.push_back(s);
    cout<< s << endl;
  }
  int j = 0;
  int loopMax = 0;
  int vertex = 0;
  int neighbor;
  for(int i = 0; i < v_input.size(); i++){
    loopMax += vertCount;
    neighbor = 0;
    for(j = i; j < loopMax; j++){
      const char *str1 = v_input.at(j).c_str();
      int temp = atoi(str1);
      if(temp == 1)
        graph[vertex].addToEnd(neighbor);

      neighbor++;
    }
    i = loopMax-1;
    vertex++;
  }
  //CREATE visited ARRAY TO KEEP TRACK OF THE VERTICIES THAT HAVE
  //AND HAVE NOT BEEN VISITED.  IF i = VISITED, visited[i]=1
  //ELSE visited[i]=0
  int visited[vertCount];

  //INITIALLY NO NODE HAS BEEN VISITED
  for (int i=0; i < vertCount; i++){
    visited[i] = 0;
    //TEST cout<< "visited " << i << " = " << visited[i] << endl;
  }

  //CREATE STACK.  EVERY TIME WE VISIT A VERTEX, IF IT HAS NOT BEEN
  //VISITED, PUSH THAT VERTEX ONTO THE TOP OF THE STACK.  REMOVE
  //VERTEX FROM THE TOP OF THE STACK WHEN THAT VERTEX HAS NO
  //UNVISITED neighbor
  stack<int> neighborhood;

  cout<< "\nThe correct DFS path of visited nodes is :" << endl;
  int v = 0;

  do{
    if(visited[v] == 0){                    //***curr vertex has not been visited***
      cout<< v << endl;                     //print vertex
      visited[v] = 1;                       //mark vertex as visited
      neighborhood.push(v);                 //push vertex onto stack

      if(graph[v].showNeighbor() != 0){     //vertex has a neighbor
        v = graph[v].showNeighbor();        //move to neighbor vertex ^
      }
      else{                                  //vertex does not have a neighbor
        neighborhood.pop();                  //pop vertex out of stack
        v = neighborhood.top();              //go back to previous vertex
        graph[v].killNeighbor();             //remove vertex that was just popped as a neighbor of cur. vertex ^
      }
    }
    else{                                    //***curr vertex has been visited***
      if(graph[v].showNeighbor() !=0){       //curr vertex has a neighbor
        v = graph[v].showNeighbor();         //move to neighbor vertex ^
      }
      else{                                  //curr vertex has no neighbor
        neighborhood.pop();                  //pop vertex out of stack
        if(!neighborhood.empty()){           //stack is not empty
          v = neighborhood.top();            //go back to previous vertex
          graph[v].killNeighbor();           //remove vertex that was just popped from neighbor of curr. vertex ^
        }
      }
    }

  }while(!neighborhood.empty());

  return 0;
}
