//This file implements the Stack Class

template<typename T>
T& Stack<T>::top(){
  if(isEmpty())
    throw std::runtime_error("Top of empty Stack");
  else
    return top_->element;
}
template<typename T>
void Stack<T>::push(const T& elem){
  NodePtr item = new Node(elem, top_);
  top_ = item;
  size_++;
}
template<typename T>
T Stack<T>::pop() {
  if(isEmpty())
    throw std::runtime_error("Top of empty Stack");
  NodePtr old = top_;
  top_ = top_->next;
  size_--;
  T result = old->element;
  delete old;
  return result;
}
//May be use std::move
template<typename T>
void Stack<T>::copyFrom(const Stack<T>& ls){
  if(top_ != NULL)
    removeAll(); // Should I do this
  top_ = NULL;
  NodePtr currNode = ls.top_;
  NodePtr prev     = NULL;
  while(currNode != NULL){
    NodePtr newNode = new Node(currNode->element, NULL);
    if(top_ == NULL){ top_ = newNode;}
    else{ prev->next = newNode;}

    prev = newNode;
    currNode = currNode->next;
  }
  size_ = ls.size_;
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& list){
  if(this != &list){ //check against self copy
    removeAll();
    copyFrom(list);
  }
  return *this;
}

template<typename T>
void Stack<T>::display(){
  if(top_ == NULL)
    cout << "The list is empty\n";
  cout << "Displaying elements in the Stack : ( ";
  NodePtr dispNode = top_;
  while(dispNode != NULL){
    cout << dispNode->element <<", " ;
    dispNode = dispNode->next;
  }
  if(dispNode == NULL)
    cout << " )\n" ;

}
template<typename T>
void Stack<T>::removeAll(){
  while(!isEmpty()) pop();
}
template<typename T>
Stack<T>::Stack(const Stack<T>& list){
   copyFrom(list);
 }
