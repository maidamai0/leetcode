/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.09%)
 * Likes:    3106
 * Dislikes: 3724
 * Total Accepted:    995.1K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given a large integer represented as an integer array digits, where
 * each digits[i] is the i^th digit of the integer. The digits are ordered from
 * most significant to least significant in left-to-right order. The large
 * integer does not contain any leading 0's.
 *
 * Increment the large integer by one and return the resulting array of
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 *
 * Example 2:
 *
 *
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 *
 * Example 3:
 *
 *
 * Input: digits = [0]
 * Output: [1]
 * Explanation: The array represents the integer 0.
 * Incrementing by one gives 0 + 1 = 1.
 * Thus, the result should be [1].
 *
 *
 * Example 4:
 *
 *
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    unsigned char carry = 1;
    for (int i = static_cast<int>(digits.size() - 1); i >= 0; --i) {
      digits[i] += carry;
      carry = static_cast<unsigned char>(digits[i] / 10);
      digits[i] %= 10;
    }

    if (carry) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  vector<int> digits{1, 2, 3};
  vector<int> result{1, 2, 4};
  CHECK(s.plusOne(digits) == result);
}

TEST_CASE("example 2") {
  Solution s;
  vector<int> digits{4, 3, 2, 1};
  vector<int> result{4, 3, 2, 2};
  CHECK(s.plusOne(digits) == result);
}
