/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <array>
#include <vector>

#include <doctest/doctest.h>

using std::vector;

// @lc code=start
class Solution {
public:
  vector<int> countBits(int num) { return kernighan(num); }

private:
  vector<int> brute_fource(const int num) const {
    vector<int> ret(num + 1, 0);
    constexpr auto integer_size = sizeof(int) * 8;
    for (int i = 1; i <= num; ++i) {
      unsigned char sum = 0;
      for (size_t j = 0; j < integer_size; ++j) {
        sum += (i & (int(1) << j)) > 0;
      }
      ret[i] = sum;
    }

    return ret;
  }

  vector<int> dynamic_programming(const int num) const {
    vector<int> ret(num + 1, 0);
    if (num == 0) {
      return ret;
    }

    if (num == 1) {
      ret[1] = 1;
      return ret;
    }

    ret[1] = 1;

    bool is_even = true;
    constexpr auto integer_size = sizeof(int) * 8;
    for (int i = 2; i <= num; ++i) {
      if (is_even) {
        is_even = false;
        unsigned char sum = 0;
        for (size_t j = 0; j < integer_size; ++j) {
          sum += (i & (int(1) << j)) > 0;
        }
        ret[i] = sum;
      } else {
        is_even = true;
        ret[i] = ret[i - 1] + 1;
      }
    }

    return ret;
  }

  vector<int> kernighan(const int num) {
    std::vector<int> ret(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
      ret[i] = ret[i & (i - 1)] + 1;
    }
    return ret;
  }
};
// @lc code=end

TEST_CASE("counting_bits") {
  Solution sl;
  CHECK(sl.countBits(2) == std::vector<int>{0, 1, 1});
  CHECK(sl.countBits(5) == std::vector<int>{0, 1, 1, 2, 1, 2});
}
