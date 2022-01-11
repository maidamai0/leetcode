/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (32.97%)
 * Likes:    2177
 * Dislikes: 365
 * Total Accepted:    284.5K
 * Total Submissions: 860.6K
 * Testcase Example:  '1'
 *
 * Given an integer columnNumber, return its corresponding column title as it
 * appears in an Excel sheet.
 *
 * For example:
 *
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 *
 *
 *
 * Example 1:
 *
 *
 * Input: columnNumber = 1
 * Output: "A"
 *
 *
 * Example 2:
 *
 *
 * Input: columnNumber = 28
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: columnNumber = 701
 * Output: "ZY"
 *
 *
 * Example 4:
 *
 *
 * Input: columnNumber = 2147483647
 * Output: "FXSHRXW"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= columnNumber <= 2^31 - 1
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    std::string res;
    while (columnNumber) {
      res.push_back('A' + (columnNumber - 1) % 26);
      columnNumber = (columnNumber - 1) / 26;
    }

    std::reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

TEST_CASE("168. excel-sheet-column-title") {
  Solution s;
  CHECK(s.convertToTitle(1) == "A");
  CHECK(s.convertToTitle(28) == "AB");
  CHECK(s.convertToTitle(701) == "ZY");
  CHECK(s.convertToTitle(2147483647) == "FXSHRXW");
}