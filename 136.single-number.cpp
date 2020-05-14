/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "doctest/doctest.h"

using namespace std;

std::vector<int> test_case1{2, 2, 1};
std::vector<int> test_case2{4, 1, 2, 1, 2};

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    std::map<int, int> dict;
    for (const auto num : nums) {
      ++dict[num];
    }

    for (const auto kv : dict) {
      if (kv.second == 1) {
        return kv.first;
      }
    }

    return 0;
  }

  int singleNumber_xor(vector<int> &nums) {

    int n = 0;
    for (const auto num : nums) {
      n ^= num;
    }
    return n;
  }

  int singleNumber_set(vector<int> &nums) {
    std::set<int> temp;
    for (const auto num : nums) {
      auto res = temp.insert(num);
      if (!std::get<1>(res)) {
        temp.erase(std::get<0>(res));
      }
    }
    return *temp.begin();
  }
};
// @lc code=end

TEST_CASE("single number") {
  Solution solution;
  CHECK(solution.singleNumber(test_case1) == 1);
  CHECK(solution.singleNumber(test_case2) == 4);

  CHECK(solution.singleNumber_xor(test_case1) == 1);
  CHECK(solution.singleNumber_xor(test_case2) == 4);

  CHECK(solution.singleNumber_set(test_case1) == 1);
  CHECK(solution.singleNumber_set(test_case2) == 4);
}
