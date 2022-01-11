#include "common/common.hpp"

/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

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
  int maxDepth(TreeNode *root) { return max_depth(root); }

private:
  int max_depth(TreeNode *node) {
    if (!node) {
      return 0;
    }

    const auto left_depth = max_depth(node->left);
    const auto right_depth = max_depth(node->right);

    return std::max(left_depth, right_depth) + 1;
  }
};
// @lc code=end
TEST_CASE("104.maximum-depth-of-binary-tree") {
  Solution s;
  {
    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    CHECK(s.maxDepth(root) == 3);
  }

  {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    CHECK(s.maxDepth(root) == 3);
  }

  {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    CHECK(s.maxDepth(root) == 2);
  }

  { CHECK(s.maxDepth(nullptr) == 0); }

  {
    auto root = new TreeNode(0);
    CHECK(s.maxDepth(root) == 1);
  }
}