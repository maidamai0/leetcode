/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (31.07%)
 * Likes:    1376
 * Dislikes: 2083
 * Total Accepted:    278.9K
 * Total Submissions: 896.2K
 * Testcase Example:  '[3,2,1]'
 *
 * Given an integer array nums, return the third distinct maximum number in
 * this array. If the third maximum does not exist, return the maximum
 * number.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2.
 * The third distinct maximum is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2]
 * Output: 2
 * Explanation:
 * The first distinct maximum is 2.
 * The second distinct maximum is 1.
 * The third distinct maximum does not exist, so the maximum (2) is returned
 * instead.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2 (both 2's are counted together since they
 * have the same value).
 * The third distinct maximum is 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Can you find an O(n) solution?
 */

#include <limits>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
 public:
  int thirdMax(vector<int>& nums) { return thirdMax2(nums); }

  int thirdMax1(vector<int>& nums) {
    // can not handle third max value is std::numeric_limits<int>::min()
    auto max1 = std::numeric_limits<int>::min();
    auto max2 = std::numeric_limits<int>::min();
    auto max3 = std::numeric_limits<int>::min();
    for (auto n : nums) {
      if (n > max1) {
        max3 = max2;
        max2 = max1;
        max1 = n;
      } else if (n > max2 && n != max1) {
        max3 = max2;
        max2 = n;
      } else if (n > max3 && n != max1 && n != max2) {
        max3 = n;
      }
    }
    return max3 == std::numeric_limits<int>::min() ? max1 : max3;
  }

  int thirdMax2(vector<int>& nums) {
    std::set<int> s;
    for (const auto& n : nums) {
      s.insert(n);
      if (s.size() > 3) {
        s.erase(s.begin());
      }
    }

    if (s.size() < 3) {
      return *s.rbegin();
    } else {
      auto it = s.end();
      std::advance(it, -3);
      return *it;
    }
  }
};
// @lc code=end

TEST_CASE("414. Third Maximum Number") {
  Solution s;
  vector<int> nums{3, 2, 1};
  CHECK(s.thirdMax(nums) == 1);

  nums = {1, 2};
  CHECK(s.thirdMax(nums) == 2);

  nums = {2, 2, 3, 1};
  CHECK(s.thirdMax(nums) == 1);

  nums = {1, 2, -2147483648};
  CHECK(s.thirdMax(nums) == -2147483648);
}