/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (70.63%)
 * Likes:    7451
 * Dislikes: 102
 * Total Accepted:    918.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 */
#include "common/common.hpp"
#include <cstddef>
#include <queue>
#include <vector>
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
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return root;
    }

    std::queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      auto *node = nodes.front();
      nodes.pop();
      auto *left = node->left;
      node->left = node->right;
      node->right = left;

      if (node->left) {
        nodes.push(node->left);
      }

      if (node->right) {
        nodes.push(node->right);
      }
    }

    return root;
  }
};
// @lc code=end

TEST_CASE("226.invert-binary-tree") {
  {
    Solution s;
    auto *root = make_binary_tree({"4", "2", "7", "1", "3", "6", "9"});
    auto *res = s.invertTree(root);
    CHECK(res->val == 4);
    CHECK(res->left->val == 7);
    CHECK(res->right->val == 2);
    CHECK(res->left->left->val == 9);
    CHECK(res->left->right->val == 6);
    CHECK(res->right->left->val == 3);
    CHECK(res->right->right->val == 1);
  }

  {
    Solution s;
    auto *root = make_binary_tree({"2", "1", "3"});
    auto *res = s.invertTree(root);
    CHECK(res->val == 2);
    CHECK(res->left->val == 3);
    CHECK(res->right->val == 1);
  }

  {
    Solution s;
    auto *root = make_binary_tree({"1", "2"});
    auto *res = s.invertTree(root);
    CHECK(res->val == 1);
    CHECK(res->left == nullptr);
    CHECK(res->right->val == 2);
  }

  {
    Solution s;
    auto *res = s.invertTree(nullptr);
    CHECK(res == nullptr);
  }
}