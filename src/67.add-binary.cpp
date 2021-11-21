/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (48.87%)
 * Likes:    3686
 * Dislikes: 433
 * Total Accepted:    706.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */
#include "doctest/doctest.h"
// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0) {
      int sum = carry;
      if (i >= 0) sum += a[i--] - '0';
      if (j >= 0) sum += b[j--] - '0';
      res.push_back(sum % 2 + '0');
      carry = sum / 2;
    }
    if (carry) {
      res.push_back('1');
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

TEST_CASE("67. Add Binary") {
  Solution s;
  CHECK(s.addBinary("11", "1") == "100");
  CHECK(s.addBinary("1010", "1011") == "10101");
  CHECK(s.addBinary("100", "110010") == "110110");
  CHECK(s.addBinary("110010", "100") == "110110");
}