/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 *
 * https://leetcode.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (35.52%)
 * Likes:    1334
 * Dislikes: 221
 * Total Accepted:    80.5K
 * Total Submissions: 226.9K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * Your friend is typing his name into a keyboard. Sometimes, when typing a
 * character c, the key might get long pressed, and the character will be typed
 * 1 or more times.
 *
 * You examine the typed characters of the keyboard. Return True if it is
 * possible that it was your friends name, with some characters (possibly none)
 * being long pressed.
 *
 *
 * Example 1:
 *
 *
 * Input: name = "alex", typed = "aaleex"
 * Output: true
 * Explanation: 'a' and 'e' in 'alex' were long pressed.
 *
 *
 * Example 2:
 *
 *
 * Input: name = "saeed", typed = "ssaaedd"
 * Output: false
 * Explanation: 'e' must have been pressed twice, but it wasn't in the typed
 * output.
 *
 *
 * Example 3:
 *
 *
 * Input: name = "leelee", typed = "lleeelee"
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: name = "laiden", typed = "laiden"
 * Output: true
 * Explanation: It's not necessary to long press any character.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= name.length <= 1000
 * 1 <= typed.length <= 1000
 * name and typed contain only lowercase English letters.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    while (i < name.size() && j < typed.size()) {
      if (name[i] == typed[j]) {
        i++;
        j++;
      } else if (j > 0 && typed[j] == typed[j - 1]) {
        j++;
      } else {
        return false;
      }
    }

    for (auto k = j - 1; k < typed.size(); k++) {
      if (typed[k] != typed[j - 1]) {
        return false;
      }
    }

    return i == name.size();
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK(s.isLongPressedName("alex", "aaleex"));
}

TEST_CASE("example 2") {
  Solution s;
  CHECK(!s.isLongPressedName("saeed", "ssaaedd"));
}

TEST_CASE("example 3") {
  Solution s;
  CHECK(s.isLongPressedName("leelee", "lleeelee"));
}

TEST_CASE("example 4") {
  Solution s;
  CHECK(s.isLongPressedName("laiden", "laiden"));
}

TEST_CASE("example 5") {
  Solution s;
  CHECK(s.isLongPressedName("laiden", "llllllaiden"));
}

TEST_CASE("example 6") {
  Solution s;
  CHECK(!s.isLongPressedName("laiden", "laidenaa"));
}

TEST_CASE("example 7") {
  Solution s;
  CHECK(s.isLongPressedName("vtkgn", "vtkgnn"));
}