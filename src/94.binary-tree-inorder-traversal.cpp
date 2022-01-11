/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#include "common/common.hpp"

using namespace std;

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
    // std::vector<int> res;
    // recursive(root, res);
    // return res;
    return iterative(root);
  }

private:
  std::vector<int> recursive(TreeNode *root, std::vector<int> &result) {
    if (!root) {
      return result;
    }

    recursive(root->left, result);
    result.push_back(root->val);
    recursive(root->right, result);

    return result;
  }

  std::vector<int> iterative(TreeNode *node) {
    std::vector<int> result;
    if (!node) {
      return result;
    }

    std::stack<TreeNode *> stack;
    while (node || !stack.empty()) {
      while (node) {
        stack.push(node);
        node = node->left;
      }

      node = stack.top();
      stack.pop();
      result.push_back(node->val);
      node = node->right;
    }

    return result;
  }
};
// @lc code=end

TEST_CASE("94.binary-tree-inorder-traversal") {
  Solution s;
  {
    auto *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    auto result = s.inorderTraversal(root);
    CHECK(result == vector<int>{1, 3, 2});
  }

  {
    TreeNode *root = nullptr;
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{});
  }

  {
    auto *root = new TreeNode(1);
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{1});
  }

  {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{2, 1});
  }

  {
    auto *root = new TreeNode(1);
    root->right = new TreeNode(2);
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{1, 2});
  }

  {
    auto *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{1, 3, 2});
  }

  {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{2, 3, 1});
  }

  {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    const auto ans = s.inorderTraversal(root);
    CHECK(ans == vector<int>{4, 2, 5, 1, 6, 3, 7});
  }
}