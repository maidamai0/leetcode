/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (60.22%)
 * Likes:    3596
 * Dislikes: 189
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */
#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    std::array<char, 26> s_count{};
    std::array<char, 26> t_count{};
    for (auto c : s) {
      ++s_count[c - 'a'];
    }
    for (auto c : t) {
      ++t_count[c - 'a'];
    }
    // return std::equal(s_count.begin(), s_count.end(), t_count.begin());
    return s_count == t_count;
  }
};
// @lc code=end

TEST_CASE("242. Valid Anagram") {
  Solution s;
  CHECK(s.isAnagram("anagram", "nagaram"));
  CHECK(!s.isAnagram("rat", "car"));
}