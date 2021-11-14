/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (74.88%)
 * Likes:    2248
 * Dislikes: 107
 * Total Accepted:    387.9K
 * Total Submissions: 518.1K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an integer array nums, move all the even integers at the beginning of
 * the array followed by all the odd integers.
 *
 * Return any array that satisfies this condition.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1,2,4]
 * Output: [2,4,3,1]
 * Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be
 * accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 *
 *
 */
#include "doctest/doctest.h"
// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int odd = 0;
    int even = 1;
    while (odd < nums.size() && even < nums.size()) {
      if (is_even(nums[odd])) {
        odd++;
        even = odd + 1;
      } else if (!is_even(nums[odd]) && is_even(nums[even])) {
        swap(nums[odd++], nums[even++]);
      } else if (!is_even(nums[even])) {
        ++even;
      }
    }

    return nums;
  }

 private:
  bool is_even(const int num) { return num % 2 == 0; }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  vector<int> nums = {3, 1, 2, 4};
  vector<int> res = {2, 4, 3, 1};
  CHECK(s.sortArrayByParity(nums) == res);
}

TEST_CASE("example 2") {
  Solution s;
  vector<int> nums = {0};
  vector<int> res = {0};
  CHECK(s.sortArrayByParity(nums) == res);
}