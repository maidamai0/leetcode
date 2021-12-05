/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (54.87%)
 * Likes:    4469
 * Dislikes: 113
 * Total Accepted:    876.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given the roots of two binary trees p and q, write a function to check if
 * they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 *
 *
 * Example 1:
 *
 *
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: p = [1,2], q = [1,null,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: p = [1,2,1], q = [1,1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both trees is in the range [0, 100].
 * -10^4 <= Node.val <= 10^4
 *
 *
 */
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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
// @lc code=end

TEST_CASE("100.same-tree") {
  Solution s;

  {
    auto p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    auto q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    CHECK(s.isSameTree(p, q));
  }

  {
    auto p = new TreeNode(1);
    p->left = new TreeNode(2);

    auto q = new TreeNode(1);
    q->right = new TreeNode(2);
    CHECK(!s.isSameTree(p, q));
  }

  {
    auto p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);

    auto q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    CHECK(!s.isSameTree(p, q));
  }
}