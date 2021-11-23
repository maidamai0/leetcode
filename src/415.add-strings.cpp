/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (50.82%)
 * Likes:    2594
 * Dislikes: 474
 * Total Accepted:    400.3K
 * Total Submissions: 784.8K
 * Testcase Example:  '"11"\n"123"'
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 *
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 *
 *
 * Example 1:
 *
 *
 * Input: num1 = "11", num2 = "123"
 * Output: "134"
 *
 *
 * Example 2:
 *
 *
 * Input: num1 = "456", num2 = "77"
 * Output: "533"
 *
 *
 * Example 3:
 *
 *
 * Input: num1 = "0", num2 = "0"
 * Output: "0"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 10^4
 * num1 and num2 consist of only digits.
 * num1 and num2 don't have any leading zeros except for the zero itself.
 *
 *
 */

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  string addStrings(string num1, string num2) {
    if (num1.size() < num2.size()) {
      return addStrings(num2, num1);
    }

    string res;
    res.reserve(num1.size() + 1);
    int carry = 0;
    size_t index = 0;
    while (index < num2.size() || index < num1.size() || carry) {
      auto sum = 0;
      if (index < num2.size()) {
        sum += num2[num2.size() - 1 - index] - '0';
      }

      if (index < num1.size()) {
        sum += num1[num1.size() - 1 - index] - '0';
      }

      sum += carry;

      carry = sum / 10;
      sum %= 10;
      res.push_back(sum + '0');
      index++;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
TEST_CASE("415. add strings") {
  Solution s;
  REQUIRE(s.addStrings("11", "123") == "134");
  REQUIRE(s.addStrings("456", "77") == "533");
  REQUIRE(s.addStrings("0", "0") == "0");
}