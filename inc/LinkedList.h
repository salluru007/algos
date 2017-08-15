#include <iostream>

template<typename T>
struct ListNode
{
  T value;
  std::shared_ptr<ListNode<T> > next;

  ListNode(T _val, std::shared_ptr<ListNode<T> > _next):value(_val),next(_next){}
  ListNode():next(nullptr){}
  ListNode(std::shared_ptr<ListNode<T> > _next):next(_next){}
};

template<typename T, std::size_t N>
void CreateList(std::shared_ptr<ListNode<T> >&l, T (&a)[N])
{
  std::shared_ptr<ListNode<T> > head = l;
  for(int iter = 0; iter < N; iter++)
  {
    std::shared_ptr<ListNode<T> > node = std::make_shared<ListNode<T> >();
    node->value = a[iter];
    if(head == nullptr)
    {
      l = node;
      head = node;
    }
    else
    {
      head->next = node;
      head = node;
    }
  }
}

template<typename T>
void DisplayList(std::shared_ptr<ListNode<T> >l)
{
  std::shared_ptr<ListNode<T> > head = l;
  while(head != nullptr)
  {
    std::cout << head->value << std::endl;
    head = head->next;
  }
}
