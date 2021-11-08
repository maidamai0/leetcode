/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <algorithm>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

#include "doctest/doctest.h"

using std::vector;

// @lc code=start
class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    return priority_queue_method(stones);
  }

private:
  int sort_every_time(vector<int> &stones) {
    while (stones.size() > 1) {
      std::sort(stones.begin(), stones.end());

      const auto max = stones.back();
      stones.pop_back();

      const auto second_max = stones.back();
      stones.pop_back();

      if (max > second_max) {
        stones.push_back(max - second_max);
      }
    }

    return stones.empty() ? 0 : stones.back();
  }

  int priority_queue_method(vector<int> &stones) {
    std::priority_queue<int> priority_stones(stones.begin(), stones.end());
    while (priority_stones.size() > 1) {

      // at least 2 elements
      const auto max = priority_stones.top();
      priority_stones.pop();

      const auto second_max = priority_stones.top();
      priority_stones.pop();

      if (max > second_max) {
        priority_stones.push(max - second_max);
      }
    }

    return priority_stones.empty() ? 0 : priority_stones.top();
  }
};
// @lc code=end

vector<int> test_case_1 = {2, 7, 4, 1, 8, 1};
vector<int> test_case_2 = {2, 2};
vector<int> test_case_3 = {7, 6, 7, 6, 9};

TEST_CASE("last_stone_weight") {
  Solution sln;

  CHECK(sln.lastStoneWeight(test_case_1) == 1);
  CHECK(sln.lastStoneWeight(test_case_2) == 0);
  CHECK(sln.lastStoneWeight(test_case_3) == 3);
}
