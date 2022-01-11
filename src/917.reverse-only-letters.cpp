/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (60.59%)
 * Likes:    1259
 * Dislikes: 48
 * Total Accepted:    120.7K
 * Total Submissions: 199.2K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string s, reverse the string according to the following rules:
 *
 *
 * All the characters that are not English letters remain in the same
 * position.
 * All the English letters (lowercase or uppercase) should be reversed.
 *
 *
 * Return s after reversing it.
 *
 *
 * Example 1:
 * Input: s = "ab-cd"
 * Output: "dc-ba"
 * Example 2:
 * Input: s = "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * Example 3:
 * Input: s = "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists of characters with ASCII values in the range [33, 122].
 * s does not contain '\"' or '\\'.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      while (left < right && !isalpha(s[left])) {
        ++left;
      }
      while (left < right && !isalpha(s[right])) {
        --right;
      }

      //   if (left < right) {
      swap(s[left], s[right]);
      ++left;
      --right;
      //   }
    }

    return s;
  }

  bool is_english_letters(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }
};
// @lc code=end

TEST_CASE("example") {
  Solution s;
  CHECK(s.reverseOnlyLetters("ab-cd") == "dc-ba");
  CHECK(s.reverseOnlyLetters("a-bC-dEf-ghIj") == "j-Ih-gfE-dCba");
  CHECK(s.reverseOnlyLetters("Test1ng-Leet=code-Q!") == "Qedo1ct-eeLg=ntse-T!");
  CHECK(s.reverseOnlyLetters("----ab") == "----ba");
}