/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (65.04%)
 * Likes:    5623
 * Dislikes: 334
 * Total Accepted:    680.7K
 * Total Submissions: 1M
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an integer array nums where the elements are sorted in ascending
 * order, convert it to a height-balanced binary search tree.
 *
 * A height-balanced binary tree is a binary tree in which the depth of the two
 * subtrees of every node never differs by more than one.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3]
 * Output: [3,1]
 * Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in a strictly increasing order.
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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }

    if (nums.size() == 1u) {
      return new TreeNode(nums[0]);
    }

    const auto mid = nums.size() / 2;
    std::vector left_nums(nums.begin(), nums.begin() + mid);
    std::vector right_nums(nums.begin() + mid + 1, nums.end());

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(left_nums);
    root->right = sortedArrayToBST(right_nums);

    return root;
  }
};
// @lc code=end

TEST_CASE("108.convert-sorted-array-to-binary-search-tree") {
  Solution s;
  vector<int> nums{-10, -3, 0, 5, 9};
  auto ret = s.sortedArrayToBST(nums);
  CHECK(ret->left->left->left == nullptr);
  CHECK(ret->left->left->val == -10);
  CHECK(ret->left->val == -3);
  CHECK(ret->val == 0);
  CHECK(ret->right->val == 9);
  CHECK(ret->right->left->val == 5);
  CHECK(ret->right->right == nullptr);
}