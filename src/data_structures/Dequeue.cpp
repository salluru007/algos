#include "Queue.h"
template<typename T>
void Dequeue::push_front(const &T element){
  NodePtr node = new NodePtr();
  node->element = element;
  node->next = nullptr;
  if(first == nullptr){
    first = node;
    last = node;
  }
  else{
    node->next=first;
    first=node;
  }
}

template<typename T>
void Dequeue::push_back(const &T element){
  NodePtr node = new NodePtr();
  node->element = element;
  node->next = nullptr;
  if(last == nullptr){
    last = node;
    first = node;
  }
  else{
    last->next = node;
    last = node;
  }
}

tmeplate<typename T>
void Dequeue::pop_back(const &T element){
  if(isEmpty())
    throw std::runtime_error("Trying to pop an empty list");



}
