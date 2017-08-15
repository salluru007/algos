namespace Bag{

template<typename T> struct node{
  T item_;
  node *next_;
  node(T item, node *next){
    item_ = item;
    next_ = next;
  }
};

typedef node* link;

template<typename T>class Bag{
  Bag(){
    size_       = 0;
  }
  void add(T item){
    if(size_ == 0){
      head_ = new node(item, NULL);
      size_++;
    }
    else{
      head_ = new node(item, head_);
      size_++;
    }
  }
  bool isEmpty(){
    return size_ == 0 ;
  }
  int size(){
    return size_;
  }
  ~Bag();
  private:
    link<T> head_;
    int size_;
  }
} // end namespace
