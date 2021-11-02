/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (47.73%)
 * Likes:    5027
 * Dislikes: 8417
 * Total Accepted:    1.7M
 * Total Submissions: 3.7M
 * Testcase Example:  '[1,1,2]'
 *
 * Given an integer array nums sorted in non-decreasing order, remove the
 * duplicates in-place such that each unique element appears only once. The
 * relative order of the elements should be kept the same.
 *
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array
 * nums. More formally, if there are k elements after removing the duplicates,
 * then the first k elements of nums should hold the final result. It does not
 * matter what you leave beyond the first k elements.
 *
 * Return k after placing the final result in the first k slots of nums.
 *
 * Do not allocate extra space for another array. You must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * Custom Judge:
 *
 * The judge will test your solution with the following code:
 *
 *
 * int[] nums = [...]; // Input array
 * int[] expectedNums = [...]; // The expected answer with correct length
 *
 * int k = removeDuplicates(nums); // Calls your implementation
 *
 * assert k == expectedNums.length;
 * for (int i = 0; i < k; i++) {
 * ⁠   assert nums[i] == expectedNums[i];
 * }
 *
 *
 * If all assertions pass, then your solution will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output: 2, nums = [1,2,_]
 * Explanation: Your function should return k = 2, with the first two elements
 * of nums being 1 and 2 respectively.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,1,1,1,2,2,3,3,4]
 * Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 * Explanation: Your function should return k = 5, with the first five elements
 * of nums being 0, 1, 2, 3, and 4 respectively.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * nums is sorted in non-decreasing order.
 *
 *
 */

#include "doctest/doctest.h"

// @lc code=start
#include <vector>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    const auto original_size = nums.size();
    if (original_size < 2) {
      return original_size;
    }

    auto left = nums.begin();
    auto right = nums.begin() + 1;
    while (right != nums.end()) {
      if (*left != *right) {
        *++left = *right;
      }
      ++right;
    }

    return left - nums.begin() + 1;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  vector<int> nums{1, 1, 2};
  int k = s.removeDuplicates(nums);
  CHECK(k == 2);
  CHECK(nums[0] == 1);
  CHECK(nums[1] == 2);
}

TEST_CASE("example 2") {
  Solution s;
  vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k = s.removeDuplicates(nums);
  CHECK(k == 5);
  CHECK(nums[0] == 0);
  CHECK(nums[1] == 1);
  CHECK(nums[2] == 2);
  CHECK(nums[3] == 3);
  CHECK(nums[4] == 4);
}