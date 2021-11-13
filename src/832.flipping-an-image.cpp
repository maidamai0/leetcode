/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 *
 * https://leetcode.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (79.04%)
 * Likes:    1717
 * Dislikes: 195
 * Total Accepted:    265.8K
 * Total Submissions: 336.1K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * Given an n x n binary matrix image, flip the image horizontally, then invert
 * it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is
 * reversed.
 *
 *
 * For example, flipping [1,1,0] horizontally results in [0,1,1].
 *
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is
 * replaced by 0.
 *
 *
 * For example, inverting [0,1,1] results in [1,0,0].
 *
 *
 *
 * Example 1:
 *
 *
 * Input: image = [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row:
 * [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * n == image.length
 * n == image[i].length
 * 1 <= n <= 20
 * images[i][j] is either 0 or 1.
 *
 *
 */
#include <array>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto& row : image) {
      reverse(row);
    }

    return image;
  }

  void reverse(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      const auto left_val = nums[left];
      const auto right_val = nums[right];
      nums[left++] = kZeroOne[right_val];
      nums[right--] = kZeroOne[left_val];
    }

    if (left == right) {
      nums[left] = kZeroOne[nums[left]];
    }
  }

 private:
  const std::array<int, 2> kZeroOne = {1, 0};
};
// @lc code=end

// TEST_CASE("example 1") {
//   vector<vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
//   vector<vector<int>> expected = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
//   Solution s;
//   CHECK(s.flipAndInvertImage(image) == expected);
// }

TEST_CASE("example 2") {
  vector<vector<int>> image = {
      {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
  vector<vector<int>> expected = {
      {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}};
  Solution s;
  CHECK(s.flipAndInvertImage(image) == expected);
}