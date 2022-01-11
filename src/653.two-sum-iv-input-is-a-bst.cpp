/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (57.96%)
 * Likes:    2860
 * Dislikes: 179
 * Total Accepted:    257.5K
 * Total Submissions: 443.9K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a Binary Search Tree and a target number k, return true if
 * there exist two elements in the BST such that their sum is equal to the
 * given target.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1,3], k = 4
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: root = [2,1,3], k = 1
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: root = [2,1,3], k = 3
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
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
  bool findTarget(TreeNode* root, int k) {
    std::unordered_set<int> s;
    return findTarget2(root, k, s);
  }

  bool findTarget(TreeNode* root, int k, unordered_set<int>& s) {
    if (!root) {
      return false;
    }

    if (s.count(k - root->val)) {
      return true;
    }

    s.insert(root->val);
    return findTarget(root->left, k, s) || findTarget(root->right, k, s);
  }

  bool findTarget2(TreeNode* root, int k, unordered_set<int>& s) {
    if (!root) {
      return false;
    }

    std::vector<TreeNode*> v;
    v.push_back(root);
    while (!v.empty()) {
      auto* node = v.back();
      v.pop_back();

      int val = node->val;
      if (s.count(k - val)) {
        return true;
      }

      s.insert(val);

      if (node->right) {
        v.push_back(node->right);
      }

      if (node->left) {
        v.push_back(node->left);
      }
    }

    return false;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  CHECK(s.findTarget(root, 9) == true);
}

TEST_CASE("example 2") {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  CHECK(s.findTarget(root, 28) == false);
}

TEST_CASE("example 3") {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  CHECK(s.findTarget(root, 4) == true);
}

TEST_CASE("example 4") {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  CHECK(s.findTarget(root, 1) == false);
}

TEST_CASE("example 5") {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  CHECK(s.findTarget(root, 3) == true);
}