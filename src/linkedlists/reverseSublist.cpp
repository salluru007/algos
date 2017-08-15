#include <iostream>
#include <memory>
#include "../../inc/LinkedList.h"

using namespace std;

template<typename T>
shared_ptr<ListNode<int> > ReverseSubList(shared_ptr<ListNode<T> > &first, int start, int end)
{
  //Nothing to reverse.
  if(start == end)
    return first;

  int counter = 1;

  auto dummy_head = make_shared<ListNode<T> >(first);

  auto sublist_head = dummy_head ;

  while(counter++ < start)
  {
    sublist_head = sublist_head->next;
  }
  cout << sublist_iter->value << endl;

  auto sublist_iter = sublist_head->next;
  while(++start < end)
  {

  }

}
template<typename T>
void Reverse(shared_ptr<ListNode<T> > &prev, shared_ptr<ListNode<T> > &node)
{


}

int main()
{
  std::shared_ptr<ListNode<int> >first, second;
  int nodes[] = {11, 3, 5, 7, 2};
  CreateList(first, nodes);
  first = ReverseSubList(first, 2, 4);
  DisplayList(first);
}
