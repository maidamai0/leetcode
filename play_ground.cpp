#include <iostream>
#include <map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a Node.
// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }

    auto *cp = new Node(head->val);
    cp->next = head->next;
    cp->random = head->random;

    auto tail = cp;

    Node *tmp = nullptr;
    while (head) {
      tmp = new Node(head->val);
      tmp->next = head->next;
      tmp->random = head->random;
      tail->next = tmp;

      tail = tail->next;
      head = head->next;
    }

    return cp;
  }
};

int main(int argc, char **argv) {
  ListNode node(1);
  node.next =
      new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))));
  Solution sln;
  sln.oddEvenList(&node);
}