#pragma once

#include <algorithm>
#include <cstddef>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
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

inline TreeNode *make_binary_tree(const std::vector<std::string> values) {
  assert(!values.empty());
  auto *root = new TreeNode(std::stoi(values[0]));
  std::vector<TreeNode *> nodes{root};

  for (auto i = 1u; i < values.size(); ++i) {
    auto *parent = nodes[(i - 1) / 2];
    if (values.at(i) == "null") {
      continue;
    }

    if ((i - 1) % 2 == 0) {
      parent->left = new TreeNode(std::stoi(values[i]));
      nodes.push_back(parent->left);
    } else {
      parent->right = new TreeNode(std::stoi(values[i]));
      nodes.push_back(parent->right);
    }
  }

  return root;
}

inline auto bfs_string(TreeNode *root) {
  assert(root);
  std::vector<std::string> ret;
  std::vector<TreeNode *> nodes{root};
  while (!nodes.empty()) {
    auto *node = nodes.front();
    if (node) {
      ret.push_back(std::to_string(node->val));
      nodes.push_back(node->left);
      nodes.push_back(node->right);
    } else {
      ret.push_back("null");
    }

    nodes.erase(nodes.begin());
  }

  // last two nulls
  ret.pop_back();
  ret.pop_back();

  return ret;
}