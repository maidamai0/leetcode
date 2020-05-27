#include <iostream>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    auto *slow = head;
    auto *fast = head;

    bool has_cycle = false;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        has_cycle = true;
        break;
      }
    }

    if (!has_cycle) {
      return nullptr;
    }

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};