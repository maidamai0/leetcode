/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (52.77%)
 * Likes:    2126
 * Dislikes: 133
 * Total Accepted:    234.4K
 * Total Submissions: 443.5K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string s which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 *
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a"
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: s = "bb"
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s consists of lowercase and/or uppercase English letters only.
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  int longestPalindrome(string s) {
    std::unordered_map<char, int> count{};
    for (char c : s) {
      count[c - 'a']++;
    }

    int sum = 0;
    auto odd = false;
    for (auto [_, c] : count) {
      if (c % 2 == 0) {
        sum += c;
      } else {
        sum += c - 1;
        odd = true;
      }
    }

    return sum + (odd ? 1 : 0);
  }
};
// @lc code=end

TEST_CASE("409.longest-palindrome") {
  Solution s;
  CHECK(s.longestPalindrome("abccccdd") == 7);
  CHECK(s.longestPalindrome("a") == 1);
  CHECK(s.longestPalindrome("bb") == 2);
  CHECK(s.longestPalindrome("ccc") == 3);
  CHECK(s.longestPalindrome("cccddd") == 5);
  CHECK(s.longestPalindrome("AAAAAA") == 6);
}
