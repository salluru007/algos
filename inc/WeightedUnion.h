#include<iostream>
using namespace std;

class WeightedQuickUnionUF{

private:
  int *m_size;
  int *m_id;
  int m_count;
public:
  WeightedQuickUnionUF(int _N):m_count(_N){
    m_id   = new int[_N];
    m_size = new int[_N];
    for(int iter =0 ; iter < _N; iter++){
        m_id[iter]    = iter;
        m_size[iter]  = 1;
    }
  };
  ~WeightedQuickUnionUF(){
    delete m_id;
    delete m_size;
  };
  int count(){
    return m_count;
  };
  int find(int p){
    while(p!=m_id[p]) p = m_id[p];
    return p;
  };
  bool connected(int p, int q){
    return (find(p) == find(q));
  };
  void getUnion(int p, int q){
    int i = find(p);
    int j = find (q);
    
    if(i == j) return;

    //Make smaller root point to larger one
    if(m_size[i] < m_size[j]) {m_id[i] = j ; m_size[j]+=m_size[i]; }
    else {m_id[j] = i; m_size[i] += m_size[j];}
    m_count--;
  };
};
