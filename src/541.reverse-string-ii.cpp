/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (49.88%)
 * Likes:    757
 * Dislikes: 2018
 * Total Accepted:    132.7K
 * Total Submissions: 266.1K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * Given a string s and an integer k, reverse the first k characters for every
 * 2k characters counting from the start of the string.
 *
 * If there are fewer than k characters left, reverse all of them. If there are
 * less than 2k but greater than or equal to k characters, then reverse the
 * first k characters and left the other as original.
 *
 *
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^4
 *
 *
 */

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    int n = s.size();
    int i = 0;
    while (i < n) {
      int j = min(i + k - 1, n - 1);
      reverse(s.begin() + i, s.begin() + j + 1);
      i += 2 * k;
    }
    return s;
  }

  void reverse(string::iterator begin, string::iterator end) {
    while (begin < end) {
      swap(*begin, *(end - 1));
      begin++;
      end--;
    }
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK_EQ(s.reverseStr("abcdefg", 2), "bacdfeg");
}

TEST_CASE("example 1") {
  Solution s;
  CHECK_EQ(s.reverseStr("abcd", 2), "bacd");
}
