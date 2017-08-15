#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<memory>
#include "WeightedUnion.h"
using namespace std;

int main(int argc, char *argv[]){
  //check for null arguments
  if(argv[1] == nullptr){
    cout << "Please rerun the program with a text file as input\n";
    return -1;
    }
  //argv[0] is always the object file name
  ifstream source(argv[1]);
  string line;
  //check if file is opened
  if(!source.is_open()){
    cout << "File couldn't be opened \n";
    return -1;
  }
  int N = 0;
  if(getline(source, line)){
    if(line==""){
      cout << "Nothing to process here\n";
      return -1;
    }
    N = stoi(line);
    if(N==0){
        cout << "Nothing to process here\n";
        return -1;
    }
  }

  string::size_type  sz;
  //new operator needs to be used with dynamic memory alloc
  //no new() needed if we do WeightedQuickUnionUF uf;
  WeightedQuickUnionUF *uf = new WeightedQuickUnionUF(N);
  while(getline(source, line)){
    int p = stoi(line, &sz);
    int q = stoi(line.substr(sz));
    if(uf->connected(p, q)) continue;
    uf->getUnion(p, q);
    cout << p << " " << q << "\n";
    }
    cout << uf->count() << " components\n";
    delete uf;
}
