/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 *
 * https://leetcode.com/problems/merge-strings-alternately/description/
 *
 * algorithms
 * Easy (74.28%)
 * Likes:    348
 * Dislikes: 5
 * Total Accepted:    38.4K
 * Total Submissions: 51.7K
 * Testcase Example:  '"abc"\n"pqr"'
 *
 * You are given two strings word1 and word2. Merge the strings by adding
 * letters in alternating order, starting with word1. If a string is longer
 * than the other, append the additional letters onto the end of the merged
 * string.
 *
 * Return the merged string.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q
 * merged: a p b q c   d
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 100
 * word1 and word2 consist of lowercase English letters.
 *
 */
#include "doctest/doctest.h"
// @lc code=start
class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    int w1 = 0;
    int w2 = 0;
    bool use_w1 = true;
    string res;
    while (w1 < word1.size() && w2 < word2.size()) {
      if (use_w1) {
        res += word1[w1];
        w1++;
      } else {
        res += word2[w2];
        w2++;
      }
      use_w1 = !use_w1;
    }

    while (w1 < word1.size()) {
      res += word1[w1];
      w1++;
    }

    while (w2 < word2.size()) {
      res += word2[w2];
      w2++;
    }

    return res;
  }
};
// @lc code=end

TEST_CASE("1768.merge-strings-alternately") {
  Solution s;
  CHECK(s.mergeAlternately("abc", "pqr") == "apbqcr");
  CHECK(s.mergeAlternately("ab", "pqrs") == "apbqrs");
  CHECK(s.mergeAlternately("abcd", "pq") == "apbqcd");
}