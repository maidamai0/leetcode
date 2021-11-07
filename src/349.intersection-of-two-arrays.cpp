/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (67.44%)
 * Likes:    2052
 * Dislikes: 1766
 * Total Accepted:    564.7K
 * Total Submissions: 836.8K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
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
 */
#include <unordered_set>
#include <vector>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_set<int> s1(nums1.begin(), nums1.end());
    std::unordered_set<int> s2(nums2.begin(), nums2.end());
    std::vector<int> res;
    for (auto& n1 : s1) {
      if (s2.find(n1) != s2.end()) {
        res.push_back(n1);
      }
    }

    return res;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  vector<int> nums1{1, 2, 2, 1};
  vector<int> nums2{2, 2};
  vector<int> ans{2};
  CHECK_EQ(Solution().intersection(nums1, nums2), ans);
}

TEST_CASE("example 2") {
  vector<int> nums1{4, 9, 5};
  vector<int> nums2{9, 4, 9, 8, 4};
  vector<int> ans{4, 9};
  vector<int> ans1{9, 4};
  Solution sl;
  const auto pass = sl.intersection(nums1, nums2) == ans ||
                    sl.intersection(nums1, nums2) == ans1;
  CHECK(pass);
}