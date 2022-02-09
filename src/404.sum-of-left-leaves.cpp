/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (54.52%)
 * Likes:    2983
 * Dislikes: 236
 * Total Accepted:    324.2K
 * Total Submissions: 594K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the sum of all left leaves.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 24
 * Explanation: There are two left leaves in the binary tree, with values 9 and
 * 15 respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include "common/common.hpp"
#include <cstdint>
#include <queue>

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
  int sumOfLeftLeaves(TreeNode *root) {
    assert(root);
    std::queue<TreeNode *> nodes;
    nodes.push(root);

    int64_t sum = 0;
    while (!nodes.empty()) {
      auto *node = nodes.front();
      nodes.pop();
      if (node->left && node->left->left == nullptr &&
          node->left->right == nullptr) {
        sum += node->left->val;
      }

      if (node->left) {
        nodes.push(node->left);
      }

      if (node->right) {
        nodes.push(node->right);
      }
    }

    return sum;
  }
};
// @lc code=end

TEST_CASE("404. Sum of Left Leaves") {
  Solution s;
  {
    auto *root = new TreeNode(1);
    CHECK(s.sumOfLeftLeaves(root) == 0);
  }

  {
    auto *root = make_binary_tree({"3", "9", "20", "null", "null", "15", "7"});
    CHECK(s.sumOfLeftLeaves(root) == 24);
  }
}