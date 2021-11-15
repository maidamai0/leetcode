/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 *
 * https://leetcode.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (51.23%)
 * Likes:    1311
 * Dislikes: 437
 * Total Accepted:    213.6K
 * Total Submissions: 417.1K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * Given a fixed-length integer array arr, duplicate each occurrence of zero,
 * shifting the remaining elements to the right.
 *
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place and do not return
 * anything.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,0,2,3,0,4,5,0]
 * Output: [1,0,0,2,3,0,0,4]
 * Explanation: After calling your function, the input array is modified to:
 * [1,0,0,2,3,0,0,4]
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,3]
 * Output: [1,2,3]
 * Explanation: After calling your function, the input array is modified to:
 * [1,2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 9
 *
 *
 */

#include <vector>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    std::vector<int> original = arr;
    int i = 0;
    int j = 0;
    while (i < original.size() && j < arr.size()) {
      const auto n = original[i];
      arr[j++] = n;
      if (n == 0 && j < original.size()) {
        arr[j++] = n;
      }
      ++i;
    }
  }
};
// @lc code=end

TEST_CASE("example 1") {
  vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
  Solution().duplicateZeros(arr);
  CHECK(arr == vector<int>{1, 0, 0, 2, 3, 0, 0, 4});
}

TEST_CASE("example 2") {
  vector<int> arr = {1, 2, 3};
  Solution().duplicateZeros(arr);
  CHECK(arr == vector<int>{1, 2, 3});
}

TEST_CASE("example 3") {
  vector<int> arr = {8, 4, 5, 0, 0, 0, 0, 7};
  Solution().duplicateZeros(arr);
  CHECK(arr == vector<int>{8, 4, 5, 0, 0, 0, 0, 0});
}