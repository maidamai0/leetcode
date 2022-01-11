/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (75.51%)
 * Likes:    2015
 * Dislikes: 129
 * Total Accepted:    329.5K
 * Total Submissions: 435.2K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 *
 *
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 *
 *
 */
#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    decltype(s.size()) begin = 0;
    auto end = s.find(' ');
    while (end != string::npos) {
      revserWord(s, begin, end - 1);
      begin = end + 1;
      end = s.find(' ', begin);
    }

    revserWord(s, begin, s.size() - 1);
    return s;
  }

  void revserWord(std::string& s, decltype(s.size()) begin,
                  decltype(s.size()) end) {
    while (begin < end) {
      std::swap(s[begin++], s[end--]);
    }
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK_EQ(s.reverseWords("Let's take LeetCode contest"),
           "s'teL ekat edoCteeL tsetnoc");
}

TEST_CASE("example 2") {
  Solution s;
  CHECK_EQ(s.reverseWords("God Ding"), "doG gniD");
}
