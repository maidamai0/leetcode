/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

#include "doctest/doctest.h"
#include <vector>

using namespace std;

std::vector<std::vector<int>> test_cases = {
    {0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}, {0, 0, 0, 1},    {1, 0, 0, 0},
    {1, 0, 0, 0},     {1, 0, 0, 0},     {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};

// @lc code=start
class Solution {
public:
  void moveZeroes(vector<int> &nums) { official(nums); }

private:
  void brute_force(vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); ++i) {

      bool all_zero_left = true;
      // current element is zero
      if (nums[i] == 0) {

        //  find next non-zero element
        for (size_t j = i + 1; j < nums.size(); ++j) {
          if (nums[j] != 0) {
            std::swap(nums[i], nums[j]);
            all_zero_left = false;
            break;
          }
        }

        if (all_zero_left) {
          return;
        }
      }
    }
  }

  // O(n), fastest
  void skip_swap(std::vector<int> &nums) {
    size_t left_most_zero = 0;
    for (size_t i = 0; i < nums.size(); ++i) {

      //  zero element
      if (nums[i] == 0) {
        if (nums[left_most_zero] != 0) {
          left_most_zero = i;
        }
      } else if (nums[left_most_zero] == 0) {
        std::swap(nums[i], nums[left_most_zero]);
        ++left_most_zero;
      }
    }
  }

  // O(n)
  void official(std::vector<int> &nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
      if (nums[cur] != 0) {
        swap(nums[lastNonZeroFoundAt++], nums[cur]);
      }
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
