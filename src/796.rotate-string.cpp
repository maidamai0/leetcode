/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 *
 * https://leetcode.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (50.26%)
 * Likes:    1519
 * Dislikes: 78
 * Total Accepted:    124.4K
 * Total Submissions: 246.2K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * Given two strings s and goal, return true if and only if s can become goal
 * after some number of shifts on s.
 *
 * A shift on s consists of moving the leftmost character of s to the rightmost
 * position.
 *
 *
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 *
 *
 *
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  bool rotateString(string s, string goal) {
    return s.size() == goal.size() && (s + s).find(goal) != string::npos;
  }
};
// @lc code=end

TEST_CASE("796.rotate-string") {
  Solution s;
  REQUIRE(s.rotateString("abcde", "cdeab"));
  REQUIRE(s.rotateString("abcde", "abced") == false);
}