/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (57.65%)
 * Likes:    4220
 * Dislikes: 2719
 * Total Accepted:    824.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 * range [0,3]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the
 * range [0,2]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Explanation: n = 9 since there are 9 numbers, so all numbers are in the
 * range [0,9]. 8 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [0]
 * Output: 1
 * Explanation: n = 1 since there is 1 number, so all numbers are in the range
 * [0,1]. 1 is the missing number in the range since it does not appear in
 * nums.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 *
 *
 *
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 *
 */
#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int expected = 0;
    int actual = 0;
    for (int i = 0; i < nums.size(); i++) {
      expected += i;
      actual += nums[i];
    }
    expected += nums.size();

    return expected - actual;
  }

 private:
  int missingNumber_xor(vector<int>& nums) {
    auto result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      result ^= i;
      result ^= nums[i];
    }
    result ^= nums.size();
    return result;
  }
};
// @lc code=end

TEST_CASE("missing-number") {
  Solution s;
  vector<int> nums{3, 0, 1};
  CHECK(s.missingNumber(nums) == 2);

  nums = {0, 1};
  CHECK(s.missingNumber(nums) == 2);

  nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  CHECK(s.missingNumber(nums) == 8);

  nums = {0};
  CHECK(s.missingNumber(nums) == 1);
}