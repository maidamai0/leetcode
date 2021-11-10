/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (49.97%)
 * Likes:    3276
 * Dislikes: 259
 * Total Accepted:    355.5K
 * Total Submissions: 711.3K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 *
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 *
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */

#include <stdint.h>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.size() > t.size()) {
      return false;
    }

    int32_t s_i = 0;
    int32_t t_i = 0;

    while (t_i < t.size() && s_i < s.size()) {
      if (s[s_i] == t[t_i]) {
        s_i++;
        t_i++;
      } else {
        t_i++;
      }
    }

    return s_i == s.size();
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK(s.isSubsequence("abc", "ahbgdc"));
}

TEST_CASE("example 2") {
  Solution s;
  CHECK(!s.isSubsequence("axc", "ahbgdc"));
}

TEST_CASE("example 3") {
  Solution s;
  CHECK(s.isSubsequence("", "ahbgdc"));
}

TEST_CASE("example 4") {
  Solution s;
  CHECK(!s.isSubsequence("abc", ""));
}