//This class implements a double ended queue without an 
template class<typename T> Dequeue{
protected:
  struct Node{
    T element;
    Node *next;
    Node(T _e/*what should I put here*/, Node *_nxt = nullptr):element(_e), next(_nxt){}
  };
  typedef Node* NodePtr;
private:
  int m_size;
  NodePtr first;
  NodePtr last;
  Dequeue(int _sz =0, NodePtr _f=nullptr, NodePtr _l=nullptr):
  m_size(_sz), first(_f),last(_l){};

public:
  int size(){ return m_size;}
  bool isEmpty(){ return m_size !=0 };
  void removeAll();
  void push_back(const &T);
  void push_front(const &T);
  void pop_back(const &T);
  void pop_front(const &T);
  void display();
  Dequeue& operator=(const Dequeue &queue);
  Dequeue(const Dequeue &queue); //copy constructor
    ~Dequeue(){ removeAll()};

}
