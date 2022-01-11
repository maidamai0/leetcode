/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 *
 * https://leetcode.com/problems/reverse-prefix-of-word/description/
 *
 * algorithms
 * Easy (78.68%)
 * Likes:    165
 * Dislikes: 2
 * Total Accepted:    19.5K
 * Total Submissions: 24.8K
 * Testcase Example:  '"abcdefd"\n"d"'
 *
 * Given a 0-indexed string word and a character ch, reverse the segment of
 * word that starts at index 0 and ends at the index of the first occurrence of
 * ch (inclusive). If the character ch does not exist in word, do
 * nothing.
 *
 *
 * For example, if word = "abcdefd" and ch = "d", then you should reverse the
 * segment that starts at 0 and ends at 3 (inclusive). The resulting string
 * will be "dcbaefd".
 *
 *
 * Return the resulting string.
 *
 *
 * Example 1:
 *
 *
 * Input: word = "abcdefd", ch = "d"
 * Output: "dcbaefd"
 * Explanation: The first occurrence of "d" is at index 3.
 * Reverse the part of word from 0 to 3 (inclusive), the resulting string is
 * "dcbaefd".
 *
 *
 * Example 2:
 *
 *
 * Input: word = "xyxzxe", ch = "z"
 * Output: "zxyxxe"
 * Explanation: The first and only occurrence of "z" is at index 3.
 * Reverse the part of word from 0 to 3 (inclusive), the resulting string is
 * "zxyxxe".
 *
 *
 * Example 3:
 *
 *
 * Input: word = "abcd", ch = "z"
 * Output: "abcd"
 * Explanation: "z" does not exist in word.
 * You should not do any reverse operation, the resulting string is "abcd".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 250
 * word consists of lowercase English letters.
 * ch is a lowercase English letter.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  string reversePrefix(string word, char ch) {
    auto right = word.find(ch);
    if (right == string::npos) {
      return word;
    }

    auto left = 0;
    while (left < right) {
      swap(word[left++], word[right--]);
    }

    return word;
  }
};
// @lc code=end

TEST_CASE("reverse-prefix-of-word") {
  Solution s;
  CHECK(s.reversePrefix("abcdefd", 'd') == "dcbaefd");
  CHECK(s.reversePrefix("xyxzxe", 'z') == "zxyxxe");
  CHECK(s.reversePrefix("abcd", 'z') == "abcd");
}