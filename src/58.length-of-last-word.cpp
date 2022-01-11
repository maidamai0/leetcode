/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (35.03%)
 * Likes:    327
 * Dislikes: 40
 * Total Accepted:    612.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of some words separated by some number of
 * spaces, return the length of the last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int right = s.size() - 1;
    while (right >= 0 && s[right] == ' ') {
      right--;
    }

    int count = 0;
    while (right >= 0 && s[right] != ' ') {
      count++;
      right--;
    }

    return count;
  }
};

// @lc code=end
TEST_CASE("58. Length of Last Word") {
  Solution s;
  CHECK_EQ(s.lengthOfLastWord("Hello World"), 5);
  CHECK_EQ(s.lengthOfLastWord("   fly me   to   the moon  "), 4);
  CHECK_EQ(s.lengthOfLastWord("luffy is still joyboy"), 6);
}