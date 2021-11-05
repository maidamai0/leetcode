/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

#include <vector>

#include "doctest/doctest.h"

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    iterative(root);
    return res_;
  }

private:
  void recursive(TreeNode *root) {
    if (!root) {
      return;
    }

    res_.push_back(root->val);
    recursive(root->left);
    recursive(root->right);
  }

  void iterative(TreeNode *root) {
    if (!root) {
      return;
    }
    vector<TreeNode *> roots;
    roots.push_back(root);

    while (!roots.empty()) {
      const auto *node = roots.back();
      roots.pop_back();
      res_.push_back(node->val);
      if (node->right) {
        roots.push_back(node->right);
      }
      if (node->left) {
        roots.push_back(node->left);
      }
    }
  }

private:
  vector<int> res_;
};
// @lc code=end
