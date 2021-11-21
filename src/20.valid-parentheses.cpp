/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.50%)
 * Likes:    9834
 * Dislikes: 384
 * Total Accepted:    1.8M
 * Total Submissions: 4.4M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: s = "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: s = "{[]}"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */
#include "doctest/doctest.h"
// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> st;
    for (const auto& c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          st.push(c);
          break;
        case ')':
          if (st.empty() || st.top() != '(') {
            return false;
          }
          st.pop();
          break;
        case ']':
          if (st.empty() || st.top() != '[') {
            return false;
          }
          st.pop();
          break;
        case '}':
          if (st.empty() || st.top() != '{') {
            return false;
          }
          st.pop();
          break;
      }
    }

    return st.empty();
  }
};
// @lc code=end

TEST_CASE("valid-parentheses") {
  Solution s;
  CHECK(s.isValid("()"));
  CHECK(s.isValid("()[]{}"));
  CHECK(!s.isValid("(]"));
  CHECK(!s.isValid("([)]"));
  CHECK(s.isValid("{[]}"));
}