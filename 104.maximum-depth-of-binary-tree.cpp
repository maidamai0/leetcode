/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

#include <algorithm>

#include "common/common.hpp"
#include "doctest/doctest.h"

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
