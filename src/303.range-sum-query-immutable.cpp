/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (52.90%)
 * Likes:    1659
 * Dislikes: 1535
 * Total Accepted:    313.7K
 * Total Submissions: 590.6K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, handle multiple queries of the following
 * type:
 *
 *
 * Calculate the sum of the elements of nums between indices left and right
 * inclusive where left <= right.
 *
 *
 * Implement the NumArray class:
 *
 *
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * int sumRange(int left, int right) Returns the sum of the elements of nums
 * between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +
 * ... + nums[right]).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * Output
 * [null, 1, -1, -3]
 *
 * Explanation
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
 * numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
 * numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 0 <= left <= right < nums.length
 * At most 10^4 calls will be made to sumRange.
 *
 *
 */
#include <vector>

#include "doctest/doctest.h"

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) : nums_(nums) {}

  int sumRange(int left, int right) {
    return sum_range(left, right);
    int sum = 0;
    for (int i = left; i <= right; ++i) {
      sum += nums_[i];
    }
    return sum;
  }

 private:
  int sum_range(int left, int right) {
    return std::accumulate(nums_.begin() + left, nums_.begin() + right + 1, 0);
  }

 private:
  const vector<int>& nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

TEST_CASE("303.range-sum-query-immutable") {
  std::vector<int> nums{-2, 0, 3, -5, 2, -1};
  NumArray numArray(nums);
  CHECK(numArray.sumRange(0, 2) == 1);
  CHECK(numArray.sumRange(2, 5) == -1);
  CHECK(numArray.sumRange(0, 5) == -3);
}