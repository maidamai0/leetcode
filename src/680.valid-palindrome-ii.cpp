/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (37.94%)
 * Likes:    3489
 * Dislikes: 214
 * Total Accepted:    346.4K
 * Total Submissions: 912.2K
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aba"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abc"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 *
 *
 */
#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
      }
      ++i;
      --j;
    }
    return true;
  }

  bool isPalindrome(const string& s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      ++i;
      --j;
    }
    return true;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK(s.validPalindrome("aba"));
}

TEST_CASE("example 2") {
  Solution s;
  CHECK(s.validPalindrome("abca"));
}

TEST_CASE("example 3") {
  Solution s;
  CHECK(!s.validPalindrome("abc"));
}

TEST_CASE("example 4") {
  Solution s;
  CHECK(!s.validPalindrome("eeccccbebaeeabebccceea"));
}

TEST_CASE("example 5") {
  Solution s;
  CHECK(
      s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqn"
                        "cffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"));
}
