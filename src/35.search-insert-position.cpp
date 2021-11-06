/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (42.53%)
 * Likes:    5278
 * Dislikes: 330
 * Total Accepted:    1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 * Example 2:
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 * Example 4:
 * Input: nums = [1,3,5,6], target = 0
 * Output: 0
 * Example 5:
 * Input: nums = [1], target = 0
 * Output: 0
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 *
 *
 */

#include <vector>

#include "doctest/doctest.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size() - 1);
    int mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (nums[mid] < target) {
      return mid + 1;
    } else {
      return mid;
    }
  }
};
// @lc code=end

TEST_CASE("example 1") {
  vector<int> nums{1, 3, 5, 6};
  int target = 5;
  Solution s;
  CHECK(s.searchInsert(nums, target) == 2);
}

TEST_CASE("example 2") {
  vector<int> nums{1, 3, 5, 6};
  int target = 2;
  Solution s;
  CHECK(s.searchInsert(nums, target) == 1);
}

TEST_CASE("example 3") {
  vector<int> nums{1, 3, 5, 6};
  int target = 7;
  Solution s;
  CHECK(s.searchInsert(nums, target) == 4);
}

TEST_CASE("example 4") {
  vector<int> nums{1, 3, 5, 6};
  int target = 0;
  Solution s;
  CHECK(s.searchInsert(nums, target) == 0);
}

TEST_CASE("example 5") {
  vector<int> nums{1};
  int target = 0;
  Solution s;
  CHECK(s.searchInsert(nums, target) == 0);
}