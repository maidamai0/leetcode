/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#include <vector>

#include "doctest/doctest.h"

using namespace std;

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
  vector<int> inorderTraversal(TreeNode *root) {
    recursive(root);
    return result_;
  }

private:
  void recursive(TreeNode *root) {
    if (!root) {
      return;
    }

    recursive(root->left);
    result_.push_back(root->val);
    recursive(root->right);
  }

  void iterative(TreeNode *node) {
    if (!node) {
      return;
    }

    vector<TreeNode *> nodes;
    nodes.push_back(node);
    while (!nodes.empty()) {

      // run to last left
      while (node->left) {
        nodes.push_back(node->left);
        node = node->left;
      }

      // get left value
      result_.push_back(node->val);
      result_.pop_back();

      node = nodes.back();
      nodes.pop_back();
      result_.push_back(node->val);
      node = node->right;
    }
  }

private:
  vector<int> result_;
};
// @lc code=end
