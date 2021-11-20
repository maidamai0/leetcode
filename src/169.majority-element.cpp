/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (61.44%)
 * Likes:    7085
 * Dislikes: 297
 * Total Accepted:    1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 *
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */
#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    std::map<int, int> dict;
    auto max = 0;
    for (const auto num : nums) {
      ++dict[num];
      if (dict[num] > dict[max]) {
        max = num;
      }
    }

    return max;
  }
};
// @lc code=end

TEST_CASE("majority element") {
  Solution s;
  vector<int> nums{3, 2, 3};
  CHECK(s.majorityElement(nums) == 3);
  nums = {2, 2, 1, 1, 1, 2, 2};
  CHECK(s.majorityElement(nums) == 2);
}