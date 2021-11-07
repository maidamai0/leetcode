/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (53.20%)
 * Likes:    12529
 * Dislikes: 804
 * Total Accepted:    1.2M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
 * together with the x-axis forms a container, such that the container contains
 * the most water.
 *
 * Notice that you may not slant the container.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [1,1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: height = [4,3,2,1,4]
 * Output: 16
 *
 *
 * Example 4:
 *
 *
 * Input: height = [1,2,1]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 *
 *
 */
#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int max_area = 0;
    while (left < right) {
      const auto area = std::min(height[left], height[right]) * (right - left);
      max_area = std::max(max_area, area);
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }

    return max_area;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution s;
  CHECK(s.maxArea(height) == 49);
}

TEST_CASE("example 2") {
  vector<int> height{1, 1};
  Solution s;
  CHECK(s.maxArea(height) == 1);
}

TEST_CASE("example 3") {
  vector<int> height{4, 3, 2, 1, 4};
  Solution s;
  CHECK(s.maxArea(height) == 16);
}

TEST_CASE("example 4") {
  vector<int> height{1, 2, 1};
  Solution s;
  CHECK(s.maxArea(height) == 2);
}