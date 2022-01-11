/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

#include "common/common.hpp"

using std::string;

// @lc code=start
class Solution {
public:
  bool backspaceCompare(string S, string T) { return brute_force(S, T); }

private:
  bool brute_force(const string &S, const string &T) {
    return to_normal_string(S) == to_normal_string(T);
  }

  string to_normal_string(const string &str) {
    string normal;
    for (const auto c : str) {
      if (c == '#') {
        if (!normal.empty()) {
          normal.pop_back();
        }
      } else {
        normal.push_back(c);
      }
    }

    return normal;
  }
};
// @lc code=end

TEST_CASE("backspace_string_compare") {
  Solution sl;
  CHECK(sl.backspaceCompare("ab#c", "ad#c") == true);
  CHECK(sl.backspaceCompare("ab##", "c#d#") == true);
  CHECK(sl.backspaceCompare("a##c", "#a#c") == true);
  CHECK(sl.backspaceCompare("a#c", "b") == false);
}
