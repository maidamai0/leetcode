/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (45.83%)
 * Likes:    4673
 * Dislikes: 267
 * Total Accepted:    666.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
 *
 *
 */
#include "common/common.hpp"
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
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }

    const auto left_height = height(root->left);
    const auto right_height = height(root->right);
    return std::abs(left_height - right_height) <= 1;
  }

  int height(TreeNode *root) {
    if (!root) {
      return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
  }
};

// @lc code=end

TEST_CASE("balanced-binary-tree") {
  Solution s;
  {
    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    CHECK(s.isBalanced(root) == true);
  }

  {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    CHECK(s.isBalanced(root) == false);
  }

  { CHECK(s.isBalanced(nullptr) == true); }

  {
    // [ 1, 2, 2, 3, null, null, 3, 4, null, null, 4 ];
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
  }
}