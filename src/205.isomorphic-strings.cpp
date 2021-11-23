/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (41.59%)
 * Likes:    2901
 * Dislikes: 579
 * Total Accepted:    443.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    std::unordered_map<char, char> s2t;
    std::unordered_map<char, char> t2s;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s2t.find(s[i]) == s2t.end() && t2s.find(t[i]) == t2s.end()) {
        s2t[s[i]] = t[i];
        t2s[t[i]] = s[i];
      } else if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end

TEST_CASE("205. Isomorphic Strings") {
  Solution s;
  CHECK(s.isIsomorphic("egg", "add") == true);
  CHECK(s.isIsomorphic("foo", "bar") == false);
  CHECK(s.isIsomorphic("paper", "title") == true);
  CHECK(s.isIsomorphic("ab", "aa") == false);
  CHECK(s.isIsomorphic("badc", "baba") == false);
}