#include "linked-list.h"

void LinkedList::reverse()
{
  if (!head || head==tail) return;
  auto curr = head;
  ListNode* temp = curr->next->next;
  curr = curr->next;
  head->next->next = head;
  head->next = nullptr;
  while(temp!=nullptr) {
    auto in_temp = temp->next;
    temp->next = curr;
    curr = temp;
    temp = in_temp;
  }
  auto hehe = tail;
  tail = head;
  head = hehe;
}