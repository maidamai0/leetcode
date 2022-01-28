/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.88%)
 * Likes:    3589
 * Dislikes: 920
 * Total Accepted:    690.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include "common/common.hpp"
#include <algorithm>
#include <string>

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
  int minDepth(TreeNode *root) { return bfs(root); }

  int brute_force(TreeNode *root) {
    if (!root) {
      return 0;
    }

    if (!root->left) {
      return minDepth(root->right) + 1;
    }

    if (!root->right) {
      return minDepth(root->left) + 1;
    }

    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
  }

  int bfs(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int depth = 0;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      ++depth;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto *node = q.front();
        q.pop();
        if (!node->left && !node->right) {
          return depth;
        }
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }

    return depth;
  }
};
// @lc code=end

TEST_CASE("111.minimum-depth-of-binary-tree") {
  {
    Solution s;
    CHECK(s.minDepth(nullptr) == 0);
  }

  {
    Solution s;
    CHECK(s.minDepth(make_binary_tree(
              {"3", "9", "20", "null", "null", "15", "7"})) == 2);
  }

  {
    Solution s;
    auto *tree = make_binary_tree(
        {"2", "null", "3", "null", "4", "null", "5", "null", "6"});
    const auto actual = s.minDepth(tree);
    CHECK(actual == 5);
  }
}