/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.06%)
 * Likes:    5978
 * Dislikes: 2600
 * Total Accepted:    1.3M
 * Total Submissions: 3.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 *
 *
 */
#include "doctest/doctest.h"
// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (const auto& str : strs) {
      while (str.find(prefix) != 0) {
        prefix.pop_back();
        if (prefix.empty()) {
          return {};
        }
      }
    }

    return prefix;
  }
};
// @lc code=end

TEST_CASE("14. Longest Common Prefix") {
  Solution s;
  vector<string> strs = {"flower", "flow", "flight"};
  CHECK_EQ(s.longestCommonPrefix(strs), "fl");
  strs = {"dog", "racecar", "car"};
  CHECK_EQ(s.longestCommonPrefix(strs), "");
}