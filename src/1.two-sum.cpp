/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include "doctest/doctest.h"
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // return brute_force(nums, target);
    return hash_map(nums, target);
  }

 private:
  vector<int> brute_force(const vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }

    return {};
  }

  vector<int> hash_map(const vector<int> &nums, int target) {
    unordered_map<int, int> nums_map;
    for (int i = 0; i < nums.size(); ++i) {
      const auto to_be_find = target - nums[i];
      const auto found = nums_map.find(to_be_find);
      if (found != nums_map.end()) {
        return {i, found->second};
      } else {
        nums_map[nums[i]] = i;
      }
    }

    return {};
  }
};
// @lc code=end
TEST_CASE("1.two-sum") {
  Solution s;
  vector<int> nums{2, 7, 11, 15};
  int target = 9;
  vector<int> ans{0, 1};
  auto ret = s.twoSum(nums, target);
  auto ok = (ret == std::vector<int>{1, 0}) || (ret == std::vector<int>{0, 1});
  CHECK(ok);

  nums = {3, 2, 4};
  target = 6;
  ret = s.twoSum(nums, target);
  ok = (ret == std::vector<int>{1, 2}) || (ret == std::vector<int>{2, 1});
  CHECK(ok);

  nums = {3, 3};
  target = 6;
  ret = s.twoSum(nums, target);
  ok = (ret == std::vector<int>{0, 1}) || (ret == std::vector<int>{1, 0});
  CHECK(ok);
}