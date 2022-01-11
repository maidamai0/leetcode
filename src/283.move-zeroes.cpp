/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

#include "common/common.hpp"

using namespace std;

std::vector<std::vector<int>> test_cases = {
    {0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}, {0, 0, 0, 1},    {1, 0, 0, 0},
    {1, 0, 0, 0},     {1, 0, 0, 0},     {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};

// @lc code=start
class Solution {
public:
 void moveZeroes(vector<int> &nums) {
   decltype(nums.size()) left = 0;
   decltype(left) right = 0;
   while (right < nums.size()) {
     if (nums[right] != 0) {
       nums[left++] = nums[right];
     }
     right++;
   }

   while (left < nums.size()) {
     nums[left++] = 0;
   }
 }
};
// @lc code=end

TEST_CASE("move_zeros_simple") {
  Solution solution;
  size_t i = 0;
  while (i < test_cases.size()) {
    const auto &actual = test_cases[i];
    solution.moveZeroes(test_cases[i++]);
    const auto &expect = test_cases[i++];
    CHECK(actual == expect);
  }
}
