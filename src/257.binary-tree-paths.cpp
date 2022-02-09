/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.51%)
 * Likes:    3640
 * Dislikes: 171
 * Total Accepted:    478K
 * Total Submissions: 829K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any
 * order.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: ["1"]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 100].
 * -100 <= Node.val <= 100
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
  vector<string> binaryTreePaths(TreeNode *root) {
    assert(root);
    vector<string> res;
    if (!root->left && !root->right) {
      res.push_back(to_string(root->val));
      return res;
    }

    if (root->left) {
      for (auto &s : binaryTreePaths(root->left)) {
        res.push_back(to_string(root->val) + "->" + s);
      }
    }

    if (root->right) {
      for (auto &s : binaryTreePaths(root->right)) {
        res.push_back(to_string(root->val) + "->" + s);
      }
    }
    return res;
  }
};
// @lc code=end

TEST_CASE("257.binary-tree-paths") {
  Solution s;
  auto root = make_binary_tree({"1", "2", "3", "null", "5"});
  auto ans = s.binaryTreePaths(root);
  REQUIRE(ans.size() == 2);
  REQUIRE(ans[0] == "1->2->5");
  REQUIRE(ans[1] == "1->3");
}