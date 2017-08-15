    #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Node {

public:
  int element;
  Node *prev;
  Node *next;
  Node(int _e=-1, Node *_p=nullptr, Node *_n=nullptr):
  element(_e), prev(_p),next(_n){};
  Node& operator=(const Node& node){
    if(this != &node){
      element = node.element;
      prev = node.prev;
      next = node.next;
    }
    return *this;
  }
  Node(const Node& node):element(node.element),prev(node.prev), next(node.next){};
};

typedef Node* NodePtr;

int CreateList(stringstream &input, NodePtr &head, NodePtr &tail){
  int counter=0;
  int number;
  while(input >>  number){
    NodePtr node = new Node(number, nullptr, nullptr);
    counter++;
    //We will insert at the head;
    if(head==nullptr)
    {
      head = node;
      tail = node;
    }
    else{
      if(tail->prev==nullptr){
        node->prev=head;
        head->next=node;
        tail = node;
      }
      else {
        tail->next = node;
        node->prev = tail;
        tail = node;
      }
    }
  }

  return counter;
}

int GetElem(const NodePtr &head,const NodePtr &tail, const int &index){
  NodePtr travesePtr = new Node();
  travesePtr = tail;
  int iIndex = index;
  while(iIndex != 1){
    travesePtr = travesePtr->prev;
    iIndex--;
  }
  return travesePtr->element;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string inputData;
    int index          = -1;
    int mThToLastIndex = -1;
    NodePtr head = new Node();
    NodePtr tail = new Node();
    head = nullptr;
    tail = nullptr;
    int listSize;
    while(getline(cin, inputData)){
      stringstream input;
      input << inputData;
      //Reads the first input
      if(index == -1) { input >> mThToLastIndex; index++;}
      else{
        //Reads all the other inputs
        listSize = CreateList(input, head, tail);
        if(listSize == 0) cout << "No List was created\n";
        break;
      }
    }

    //Get the mth index element
    if(listSize < mThToLastIndex)
      cout << "NIL\n";
    else{
      int mThToLastElem = GetElem(head, tail, mThToLastIndex);
      cout << mThToLastElem << "\n";
    }
    //add removeall to avoid memory leaks
    return 0;
}
