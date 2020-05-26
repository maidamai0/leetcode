#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "time_measure/time_measurement.h"

using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &c) {
  os << "[";
  for (const auto e : c) {
    os << e << ",";
  }
  os << "]" << std::endl;

  return os;
}

class Node {
public:
  int val_ = 0;
  Node *prev_ = nullptr;
  Node *next_ = nullptr;
};

class MyLinkedList {
public:
  /** Initialize your data structure here. */
  MyLinkedList() {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (index >= size_ || index < 0) {
      return -1;
    }

    Node *node = head_;
    for (int i = 0; i < index; ++i) {
      node = node->next_;
    }

    return node->val_;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    auto node = new Node();
    node->val_ = val;

    if (head_) {
      node->next_ = head_;
      head_->prev_ = node;
    }
    head_ = node;

    // connect tail and head
    if (!tail_) {
      tail_ = head_;
    }

    ++size_;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    auto node = new Node();
    node->val_ = val;

    if (tail_) {
      node->prev_ = tail_;
      tail_->next_ = node;
    }
    tail_ = node;

    // connect tail and head
    if (!head_) {
      head_ = tail_;
    }

    ++size_;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (index == 0) {
      return addAtHead(val);
    }

    if (index == size_) {
      return addAtTail(val);
    }

    if (index > size_ || index < 0) {
      return;
    }

    auto next_node = head_;
    for (int i = 0; i < index; ++i) {
      next_node = next_node->next_;
    }
    auto prev_node = next_node->prev_;

    auto new_node = new Node();
    new_node->val_ = val;

    prev_node->next_ = new_node;
    new_node->prev_ = prev_node;
    new_node->next_ = next_node;
    next_node->prev_ = new_node;

    ++size_;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index >= size_ || index < 0) {
      return;
    }

    // TODO check which way is fasetr, head or tail
    auto node = head_;
    for (int i = 0; i < index; ++i) {
      node = node->next_;
    }

    auto prev_node = node->prev_;
    auto next_node = node->next_;

    if (prev_node) {
      prev_node->next_ = next_node;
    } else {
      // head is deleted
      head_ = next_node;
    }

    if (next_node) {
      next_node->prev_ = prev_node;
    } else {
      // tail is deleted
      tail_ = prev_node;
    }

    --size_;
  }

private:
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  int size_ = 0;
};

int main(int argc, char **argv) {
  // case 1
  {
    MyLinkedList link;
    link.addAtHead(1);
    link.addAtTail(3);
    link.addAtIndex(1, 2);
    std::cout << "get 1:" << link.get(1) << std::endl;
    link.deleteAtIndex(1);
    std::cout << "get 1:" << link.get(1) << std::endl;
  }

  // case 2
  {
    MyLinkedList link;
    link.addAtHead(1);
    link.addAtTail(3);
    link.addAtIndex(1, 2);
    std::cout << "get 1:" << link.get(1) << std::endl;
    link.deleteAtIndex(0);
    std::cout << "get 1:" << link.get(0) << std::endl;
  }
}