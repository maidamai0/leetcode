/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.92%)
 * Likes:    4931
 * Dislikes: 169
 * Total Accepted:    677.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto *ans = root;
    while (true) {
      if ((ans->val < p->val) && (ans->val < q->val)) {
        ans = ans->right;
      } else if ((ans->val > p->val) && (ans->val > q->val)) {
        ans = ans->left;
      } else {
        return ans;
      }
    }
  }
};
// @lc code=end

TEST_CASE("235.lowest-common-ancestor-of-a-binary-search-tree") {
  Solution s;
  {
    auto root = make_binary_tree(
        {"6", "2", "8", "0", "4", "7", "9", "null", "null", "3", "5"});
    REQUIRE(s.lowestCommonAncestor(root, root->left, root->right) == root);

    CHECK(s.lowestCommonAncestor(root, root->left, root->left->right) ==
          root->left);
  }

  {
    auto root = make_binary_tree({"2", "1"});
    REQUIRE(s.lowestCommonAncestor(root, root, root->left) == root);
  }
}