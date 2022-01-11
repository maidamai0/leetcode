/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (72.54%)
 * Likes:    3292
 * Dislikes: 847
 * Total Accepted:    1.3M
 * Total Submissions: 1.7M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 *
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 *
 *
 *
 * Follow up: Do not allocate extra space for another array. You must do this
 * by modifying the input array in-place with O(1) extra memory.
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  void reverseString(vector<char>& s) {
    decltype(s.size()) left = 0;
    auto right = s.size() - 1;
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution sl;
  vector<char> s{'h', 'e', 'l', 'l', 'o'};
  sl.reverseString(s);
  CHECK(s == vector<char>{'o', 'l', 'l', 'e', 'h'});
}

TEST_CASE("example 2") {
  Solution sl;
  vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};
  sl.reverseString(s);
  CHECK(s == vector<char>{'h', 'a', 'n', 'n', 'a', 'H'});
}