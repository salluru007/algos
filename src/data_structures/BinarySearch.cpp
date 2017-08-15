#include <iostream>
#include <vector>

<template typename T>class Node{
  T _elem;
  unique_ptr<Node<T> right, left;
  Node(T &_el=T()):_elem(_el), _right(nullptr), _left(nullptr){}
}
//Search through a BST or ordered tree
<template typename T>
bool binarySearch(Node<T> &node, T target){
  //Base case is empty tree
  if(node==NULL) return false;
  else{
    if(target == node->_elem) return true;
    else{
      if(target < node->_elem) lookup(node->_left, target);
      else lookup(node->_right, target);
    }
  }
}
//Vist left subtree, root and then right subtree
<template typename T>
void inorder(Node<T> &node){
  if(node == NULL) return;
  inorder(node->_left);
  std::cout << node->_elem << " ";
  inorder(node->_right);
}
//visit node, left subtree, right subtree
<template typename T>
void preorder(Node<T> &node){
  if(node == NULL) return;
  std::cout << node->_elem << " ";
  preorder(node->_left);
  preorder(node->_right);

}
//visit left subtree, right subtree, node
<template typename T>
void postorder(Node<T> &node){
  if(node == NULL) return;
  postorder(node->_left);
  postorder(node->_right);
  std::cout << node->_elem << " ";
}

<template typename T>
void insert(unique_ptr<Node<T> &root, std::vector<T> &&elements){
  std::vector<T>::iterator iter;
  std::vector<Node<T>> nodes;
  for(iter = elements.begin(); iter != elements.end(); ++iter){

  }
}

int main(){
  std::string input;
  std::cout << "Enter the name of the file to read from\n";
  getline(std::cin, input);
  std::fstream file_handle(input, ios::in);
  unique_ptr<Node<int>> root = new Node<int>();
  root = nullptr;
  if(!file_handle.is_open()){
    std::cout << "File could not be open\n";
    return 0;
  }
  else{
    std::vector<int> elements;
    while(getline(file_handle, input)){
      std::stringstream inputStr;
      int element;
      inputStr << input;
      inputStr >> element;
      elements.push_back(element);
    }
    insert(root, std:move(elements));
  }
}
