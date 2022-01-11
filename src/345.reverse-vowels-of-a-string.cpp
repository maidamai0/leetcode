/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (46.24%)
 * Likes:    1299
 * Dislikes: 1656
 * Total Accepted:    314.5K
 * Total Submissions: 679.7K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * cases.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    int64_t left = 0;
    int64_t right = s.size() - 1;
    while (left < right) {
      while (left < right && !isVowel(s[left])) {
        ++left;
      }

      while (left < right && !isVowel(s[right])) {
        --right;
      }

      swap(s[left], s[right]);
      ++left;
      --right;
    }

    return s;
  }

  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK_EQ(s.reverseVowels("hello"), "holle");
}

TEST_CASE("example 2") {
  Solution s;
  CHECK_EQ(s.reverseVowels("leetcode"), "leotcede");
}

TEST_CASE("empty string") {
  Solution s;
  CHECK_EQ(s.reverseVowels(""), "");
}

TEST_CASE("single character") {
  Solution s;
  CHECK_EQ(s.reverseVowels("a"), "a");
}

TEST_CASE("single vowel") {
  Solution s;
  CHECK_EQ(s.reverseVowels("aA"), "Aa");
}

TEST_CASE("multiple vowels") {
  Solution s;
  CHECK_EQ(s.reverseVowels("aAaAaA"), "AaAaAa");
}

TEST_CASE("multiple vowels and consonants") {
  Solution s;
  CHECK_EQ(s.reverseVowels("aAaAaAaA"), "AaAaAaAa");
}

TEST_CASE("same") {
  Solution s;
  CHECK_EQ(s.reverseVowels("a."), "a.");
}