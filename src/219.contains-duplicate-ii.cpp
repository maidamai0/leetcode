/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (40.07%)
 * Likes:    1859
 * Dislikes: 1633
 * Total Accepted:    394.1K
 * Total Submissions: 982.4K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 *
 *
 */
#include <iterator>
#include <unordered_map>
#include <unordered_set>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      const auto& it = map.find(nums[i]);
      if (it != map.end() && i - it->second <= k) {
        return true;
      } else {
        map[nums[i]] = i;
      }
    }

    return false;
  }
};
// @lc code=end
TEST_CASE("219.contains-duplicate-ii") {
  Solution s;
  vector<int> nums{1, 2, 3, 1};
  int k = 3;
  CHECK(s.containsNearbyDuplicate(nums, k) == true);

  nums = {1, 0, 1, 1};
  k = 1;
  CHECK(s.containsNearbyDuplicate(nums, k) == true);

  nums = {1, 2, 3, 1, 2, 3};
  k = 2;
  CHECK(s.containsNearbyDuplicate(nums, k) == false);
}