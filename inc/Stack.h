#include "exception"
using namespace std;
template<typename T>class Stack{
protected:
    struct Node{
      T element;
      Node *next;
      Node(const T& e = T(), Node *n = NULL):
      element(e), next(n){}
    };
    typedef Node* NodePtr;
private:
    NodePtr top_;
    int size_;
public:
    Stack(){
      top_ = NULL;
      size_ = 0;
    }
    int size()const{ return size_;};
    bool isEmpty()const { return size_ == 0;};
    T& top();
    void push(const T& elem);
    T pop();
    void display();
protected:
    void removeAll();
    void copyFrom(const Stack& ls);

public:
    Stack(const Stack& list); //copy constructor
    Stack& operator =(const Stack& list);
    ~Stack(){removeAll();}; //remove all elements
};
