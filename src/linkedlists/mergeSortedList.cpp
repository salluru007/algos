#include <iostream>
#include "../../inc/LinkedList.h"

template<typename T>
std::shared_ptr<ListNode<T> > MergeTwoLists(std::shared_ptr<ListNode<T> > first, std::shared_ptr<ListNode<T> > second)
{
    //Create a placeholder
    std::shared_ptr<ListNode<T> > dummy_head(std::make_shared<ListNode<T> >());
    auto tail = dummy_head;

    while(first && second)
    {
      AppendNode(first->value <= second->value? first : second, tail);
    }


    tail->next = first? first : second;
    return dummy_head->next;
}

template<typename T>
void AppendNode(std::shared_ptr<ListNode<T> > &node, std::shared_ptr<ListNode<T> > &tail)
{
  tail->next = node;
  tail = node;
  node = node->next;
}

int main()
{
  std::shared_ptr<ListNode<int> >first, second;
  int nodes[] = {2, 4, 6};
  int nodes2[] = {3};
  CreateList(first, nodes);
  CreateList(second, nodes2);
  first = MergeTwoLists(first, second);
  DisplayList(first);
}
