/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

#include <iostream>
#include <set>
#include <vector>

#include "doctest/doctest.h"

// @lc code=start
class Solution {
public:
  bool isHappy(int n) { return floyd_detection(n); }

private:
  bool std_set(int n) {
    history_.insert(n);

    const auto sum = sum_digits(n);
    if (sum == 1) {
      return true;
    } else if (history_.find(sum) != history_.end()) {
      // endless repeat
      return false;
    } else {
      return isHappy(sum);
    }
  }

  bool floyd_detection(int n) {

    auto slow = n;
    auto fast = n;

    do {
      slow = sum_digits(slow);
      fast = sum_digits(sum_digits(fast));

      if (fast == 1) {
        return true;
      }
    } while (slow != fast);

    return slow == 1;
  }

  int sum_digits(int n) {
    int sum = 0;
    while (n) {
      const auto mod = n % 10;
      sum += mod * mod;
      n /= 10;
    }

    return sum;
  }

private:
  std::set<int> history_;
};
// @lc code=end
TEST_CASE("example 1") {
  Solution s;
  CHECK(s.isHappy(19) == true);
}

TEST_CASE("example 2") {
  Solution s;
  CHECK(s.isHappy(2) == false);
}
