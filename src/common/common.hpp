#pragma once

#include <algorithm>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "doctest/doctest.h"
#include "fmt/format.h"
#include "magic_enum.hpp"

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};


template <typename T>
ListNode *CreateListNode(T value) {
  return new ListNode(value);
}

template <typename T, typename... Ts> ListNode *CreateListNode(T value, Ts... args) {
  return new ListNode(value, CreateListNode(args...));
}
