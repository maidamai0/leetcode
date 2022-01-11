/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (70.58%)
 * Likes:    1525
 * Dislikes: 67
 * Total Accepted:    168.8K
 * Total Submissions: 239.2K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array of integers nums, half of the integers in nums are odd, and
 * the other half are even.
 *
 * Sort the array so that whenever nums[i] is odd, i is odd, and whenever
 * nums[i] is even, i is even.
 *
 * Return any answer array that satisfies this condition.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3]
 * Output: [2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 2 * 10^4
 * nums.length is even.
 * Half of the integers in nums are even.
 * 0 <= nums[i] <= 1000
 *
 *
 *
 * Follow Up: Could you solve it in-place?
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int odd_index = 0;
    int even_index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 1) {
        while (odd_index < nums.size() && nums[odd_index] % 2 == 0) {
          ++odd_index;
        }
        if (odd_index < nums.size()) {
          std::swap(nums[i], nums[odd_index++]);
        }
      } else {
        while (even_index < nums.size() && nums[even_index] % 2 == 1) {
          ++even_index;
        }
        if (even_index < nums.size()) {
          std::swap(nums[i], nums[even_index++]);
        }
      }
    }

    return nums;
  }
};
// @lc code=end

TEST_CASE("sort-array-by-parity-ii") {
  Solution s;
  {
    vector<int> nums{4, 2, 5, 7};
    CHECK(s.sortArrayByParityII(nums) == vector<int>{4, 5, 2, 7});
  }

  {
    vector<int> nums{2, 3};
    CHECK(s.sortArrayByParityII(nums) == vector<int>{2, 3});
  }
}