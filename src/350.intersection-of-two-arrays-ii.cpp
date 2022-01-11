/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (53.80%)
 * Likes:    3321
 * Dislikes: 589
 * Total Accepted:    642.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> res;
    std::unordered_map<int, int> m;
    for (auto& n : nums1) {
      m[n]++;
    }

    for (auto& n : nums2) {
      if (m[n] > 0) {
        res.push_back(n);
        m[n]--;
      }
    }

    return res;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  vector<int> nums1{1, 2, 2, 1};
  vector<int> nums2{2, 2};
  vector<int> ans{2, 2};
  CHECK_EQ(Solution().intersect(nums1, nums2), ans);
}

TEST_CASE("example 2") {
  vector<int> nums1{4, 9, 5};
  vector<int> nums2{9, 4, 9, 8, 4};
  vector<int> ans{4, 9};
  vector<int> ans1{9, 4};
  const auto pass = Solution().intersect(nums1, nums2) == ans ||
                    Solution().intersect(nums1, nums2) == ans1;
  CHECK(pass);
}