/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (59.01%)
 * Likes:    2792
 * Dislikes: 891
 * Total Accepted:    1.1M1
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> s;
    for (const auto i : nums) {
      const auto [_, unique] = s.insert(i);
      if (!unique) {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end

TEST_CASE("217.contains-duplicate") {
  std::vector<int> nums1{1, 2, 3, 1};
  CHECK(Solution().containsDuplicate(nums1) == true);

  std::vector<int> nums2{1, 2, 3, 4};
  CHECK(Solution().containsDuplicate(nums2) == false);

  std::vector<int> nums3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  CHECK(Solution().containsDuplicate(nums3) == true);
}