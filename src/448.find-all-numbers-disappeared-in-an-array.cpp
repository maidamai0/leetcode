/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (57.35%)
 * Likes:    5538
 * Dislikes: 348
 * Total Accepted:    482.7K
 * Total Submissions: 829.4K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array nums of n integers where nums[i] is in the range [1, n],
 * return an array of all the integers in the range [1, n] that do not appear
 * in nums.
 *
 *
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [2]
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 *
 *
 *
 * Follow up: Could you do it without extra space and in O(n) runtime? You may
 * assume the returned list does not count as extra space.
 *
 */
#include <cstdlib>
#include <vector>

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      const auto idx = std::abs(nums[i]) - 1;
      if (nums[idx] > 0) {
        nums[idx] = -nums[idx];
      }
    }

    std::vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }

    return res;
  }
};
// @lc code=end

TEST_CASE("414.find-all-numbers-disappeared-in-an-array") {
  Solution s;
  auto nums = std::vector<int>{4, 3, 2, 7, 8, 2, 3, 1};
  auto ret = s.findDisappearedNumbers(nums);
  CHECK(ret == std::vector<int>{5, 6});

  nums = std::vector<int>{1, 1};
  ret = s.findDisappearedNumbers(nums);
  CHECK(ret == std::vector<int>{2});
}