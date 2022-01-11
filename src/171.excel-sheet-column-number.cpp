/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (58.45%)
 * Likes:    2114
 * Dislikes: 224
 * Total Accepted:    417.6K
 * Total Submissions: 713.5K
 * Testcase Example:  '"A"'
 *
 * Given a string columnTitle that represents the column title as appear in an
 * Excel sheet, return its corresponding column number.
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
 * Input: columnTitle = "A"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: columnTitle = "AB"
 * Output: 28
 *
 *
 * Example 3:
 *
 *
 * Input: columnTitle = "ZY"
 * Output: 701
 *
 *
 * Example 4:
 *
 *
 * Input: columnTitle = "FXSHRXW"
 * Output: 2147483647
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= columnTitle.length <= 7
 * columnTitle consists only of uppercase English letters.
 * columnTitle is in the range ["A", "FXSHRXW"].
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    unsigned res = 0;
    for (const auto& c : columnTitle) {
      res = res * 26 + c - 'A' + 1;
    }

    return res;
  }
};
// @lc code=end

TEST_CASE("171.excel-sheet-column-number") {
  Solution s;
  CHECK(s.titleToNumber("A") == 1);
  CHECK(s.titleToNumber("AB") == 28);
  CHECK(s.titleToNumber("ZY") == 701);
  CHECK(s.titleToNumber("FXSHRXW") == 2147483647);
}