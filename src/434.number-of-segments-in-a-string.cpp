/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.87%)
 * Likes:    376
 * Dislikes: 937
 * Total Accepted:    105.2K
 * Total Submissions: 277.7K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * You are given a string s, return the number of segments in the string. 
 *
 * A segment is defined to be a contiguous sequence of non-space characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello, my name is John"
 * Output: 5
 * Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "Hello"
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: s = "love live! mu'sic forever"
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 300
 * s consists of lower-case and upper-case English letters, digits or one of
 * the following characters "!@#$%^&*()_+-=',.:".
 * The only space character in s is ' '.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  int countSegments(string s) {
    int count = 0;
    size_t i = 0;
    while (i < s.size()) {
      if (s[i] == ' ') {
        i++;
      } else {
        count++;
        while (i < s.size() && s[i] != ' ') {
          i++;
        }
      }
    }

    return count;
  }
};
// @lc code=end
TEST_CASE("434. number of segments in a string") {
  Solution s;
  CHECK(s.countSegments("Hello, my name is John") == 5);
  CHECK(s.countSegments("Hello") == 1);
  CHECK(s.countSegments("love live! mu'sic forever") == 4);
  CHECK(s.countSegments("") == 0);
}