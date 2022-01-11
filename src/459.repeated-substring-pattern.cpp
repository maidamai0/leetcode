/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (43.44%)
 * Likes:    2893
 * Dislikes: 280
 * Total Accepted:    217.5K
 * Total Submissions: 500.5K
 * Testcase Example:  '"abab"'
 *
 * Given a string s, check if it can be constructed by taking a substring of it
 * and appending multiple copies of the substring together.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abab"
 * Output: true
 * Explanation: It is the substring "ab" twice.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aba"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abcabcabcabc"
 * Output: true
 * Explanation: It is the substring "abc" four times or the substring "abcabc"
 * twice.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    auto s2 = (s + s).substr(1, s.size() * 2 - 2);
    return s2.find(s) != string::npos;
  }
};
// @lc code=end

TEST_CASE("459. repeated-substring-pattern") {
  Solution s;
  CHECK(s.repeatedSubstringPattern("abab"));
  CHECK(!s.repeatedSubstringPattern("aba"));
  CHECK(s.repeatedSubstringPattern("abcabcabcabc"));
}