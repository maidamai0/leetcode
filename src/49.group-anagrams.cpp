/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <array>
#include <map>
#include <string>
#include <vector>

#include "doctest/doctest.h"

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    return brute_force(strs);
  }

private:
  using Counter = std::array<int, 26>; // counts occurances of 26 letters
  vector<vector<string>> brute_force(vector<string> &strs) {

    std::map<Counter, std::vector<std::string>> temp;

    // rearrange strings
    Counter cnt{0};
    for (const auto &str : strs) {
      cnt = {0};
      for (const auto c : str) {
        cnt[c - 'a']++;
      }
      temp[cnt].push_back(str);
    }

    // construct return values
    vector<vector<string>> ret;
    for (const auto &kv : temp) {
      ret.push_back(kv.second);
    }
    return ret;
  }
};
// @lc code=end

#include "algorithm"

vector<string> case_1{"eat", "tea", "tan", "ate", "nat", "bat"};

TEST_CASE("group_anagrams") {

  const auto is_in_same_group = [](const vector<vector<string>> &container,
                                   const vector<string> &target) {
    bool found_one = false;
    for (const auto &group : container) {
      if (std::find(group.cbegin(), group.cend(), target[0]) != group.cend()) {
        found_one = true;

        // this is the group all string in target should be in
        for (size_t i = 1; i < target.size(); ++i) {
          if (std::find(group.cbegin(), group.cend(), target[i]) ==
              group.cend()) {
            return false;
          }
        }

        // all strings in target are in the same group
        return true;
      }
    }

    return found_one;
  };

  Solution sl;
  const auto case_actual = sl.groupAnagrams(case_1);
  CHECK(is_in_same_group(case_actual, {"ate", "eat", "tea"}));
  CHECK(is_in_same_group(case_actual, {"nat", "tan"}));
  CHECK(is_in_same_group(case_actual, {"bat"}));
}
