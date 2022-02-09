/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (46.47%)
 * Likes:    1933
 * Dislikes: 524
 * Total Accepted:    141.1K
 * Total Submissions: 302.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given the root of a binary search tree (BST) with duplicates, return all the
 * mode(s) (i.e., the most frequently occurred element) in it.
 *
 * If the tree has more than one mode, return them in any order.
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
 */
#include "common/common.hpp"
#include <limits>
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
  vector<int> findMode(TreeNode *root) {
    assert(root);
    inorder_traversal(root);

    return res_;
  }

  void inorder_traversal(TreeNode *node) {
    if (!node) {
      return;
    }

    inorder_traversal(node->left);
    if (node->val == cur_val_) {
      ++cur_count_;
    } else {
      cur_count_ = 1;
    }
    cur_val_ = node->val;

    if (cur_count_ > max_count_) {
      res_.clear();
      res_.push_back(cur_val_);
      max_count_ = cur_count_;
    } else if (cur_count_ == max_count_) {
      res_.push_back(cur_val_);
    }

    inorder_traversal(node->right);
  }

private:
  int cur_val_ = std::numeric_limits<int>::min();
  int cur_count_ = 0;
  int max_count_ = 0;
  std::vector<int> res_;
};
// @lc code=end

TEST_CASE("501. Find Mode in Binary Search Tree") {
  {
    Solution s;
    auto *root = make_binary_tree({"1", "null", "2", "2"});
    const auto res = s.findMode(root);
    CHECK(res.size() == 1);
    CHECK(res[0] == 2);
  }

  {

    Solution s;
    auto *root = make_binary_tree({"1", "null", "2"});
    const auto res = s.findMode(root);
    CHECK(res.size() == 2);
    CHECK(res[0] == 1);
    CHECK(res[1] == 2);
  }

  {
    Solution s;
    auto *root = make_binary_tree({"0"});
    const auto res = s.findMode(root);
    CHECK(res.size() == 1);
    CHECK(res[0] == 0);
  }
}