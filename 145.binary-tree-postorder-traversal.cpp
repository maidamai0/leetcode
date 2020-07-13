/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

#include <algorithm>
#include <iterator>
#include <vector>

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
  vector<int> postorderTraversal(TreeNode *root) {
    iterative(root);
    return result_;
  }

private:
  void recursive(TreeNode *node) {
    if (!node) {
      return;
    }

    recursive(node->left);
    recursive(node->right);
    result_.push_back(node->val);
  }

  void iterative(TreeNode *node) {
    if (!node) {
      return;
    }

    vector<TreeNode *> first_nodes;
    vector<TreeNode *> second_nodes;
    first_nodes.push_back(node);

    while (!first_nodes.empty()) {
      const auto temp = first_nodes.back();
      first_nodes.pop_back();
      second_nodes.push_back(temp);

      if (temp->left) {
        first_nodes.push_back(temp->left);
      }

      if (temp->right) {
        first_nodes.push_back(temp->right);
      }
    }

    while (!second_nodes.empty()) {
      result_.push_back(second_nodes.back()->val);
      second_nodes.pop_back();
    }
  }

private:
  vector<int> result_;
};
// @lc code=end
