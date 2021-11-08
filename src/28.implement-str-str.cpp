/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (35.70%)
 * Likes:    3108
 * Dislikes: 2933
 * Total Accepted:    1M
 * Total Submissions: 2.9M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 *
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 *
 *
 * Constraints:
 *
 *
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack and needle consist of only lower-case English characters.
 *
 *
 */
#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }

    int left = 0;
    int right = needle.size() - 1;
    while (right < haystack.size()) {
      if (std::equal(needle.begin(), needle.end(), haystack.begin() + left)) {
        return left;
      } else {
        left++;
        right++;
      }
    }

    return -1;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK(s.strStr("hello", "ll") == 2);
}

TEST_CASE("example 2") {
  Solution s;
  CHECK(s.strStr("aaaaa", "bba") == -1);
}

TEST_CASE("example 3") {
  Solution s;
  CHECK(s.strStr("", "") == 0);
}
