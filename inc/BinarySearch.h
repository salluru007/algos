#include "iostream"
#include "queue"
using namespace std;
template<typename K, typename V> class BinarySearch{
protected:
  struct Node{
    K _key;
    V _value;
    Node *_left, *_right;
    Node(K &k = K(), V &v= V()):
    _key(k), _value(v), _left(NULL), _right(NULL){}
  };
  typedef Node* NodePtr;
private:
  NodePtr root;
  int size(NodePtr node);
  Node min(NodePtr x);
  Node max(NodePtr x);
  Node floor(Node x, K key);
  Node select(Node x, int k);
  int rank(K key, Node x);
  Node deleteMin(Node x);
  Node deleteMax(Node x);
  Node delete(Node x, K key);
  void keys(Node x, queue<K> listOfKeys, Key lo, Key hi);
public:
  int size()const;
  V get(K key);
  void put(K key, V Value);
  K min();
  K max();
  K floor(K key);
  K select(int k);
  int rank (K key);
  void deleteMin();
  void deleteMax();
  void delete(K key);
  queue<T> keys();
  queue<T> keys(K lo, K high);
}
