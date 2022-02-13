/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (41.86%)
 * Likes:    1244
 * Dislikes: 988
 * Total Accepted:    281.7K
 * Total Submissions: 673K
 * Testcase Example:  '6'
 *
 * An ugly number is a positive integer whose prime factors are limited to 2,
 * 3, and 5.
 *
 * Given an integer n, return true if n is an ugly number.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6
 * Output: true
 * Explanation: 6 = 2 × 3
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: true
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * limited to 2, 3, and 5.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 14
 * Output: false
 * Explanation: 14 is not ugly since it includes the prime factor 7.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 */
#include "common/common.hpp"

// @lc code=start
class Solution {
public:
  Solution() {
    ugly_cache_[1] = true;
    ugly_cache_[2] = true;
    ugly_cache_[3] = true;
    ugly_cache_[4] = true;
    ugly_cache_[5] = true;
  }

  bool isUgly(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 5 == 0) {
      n /= 5;
    }

    while (n % 3 == 0) {
      n /= 3;
    }

    while (n % 2 == 0) {
      n /= 2;
    }

    return ugly_cache_[n];
  }

private:
  std::map<int, bool> ugly_cache_;
};
// @lc code=end

TEST_CASE("ugly-number") {
  Solution s;
  CHECK(s.isUgly(1) == true);
  CHECK(s.isUgly(6) == true);
  CHECK(s.isUgly(14) == false);
}