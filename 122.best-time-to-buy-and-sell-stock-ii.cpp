/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include "doctest/doctest.h"
#include <vector>

auto case_1 = std::vector<int>{7, 1, 5, 3, 6, 4};
auto case_2 = std::vector<int>{1, 2, 3, 4, 5};
auto case_3 = std::vector<int>{7, 6, 4, 3, 1};

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) { return brute_force_1(prices); }

private:
  int brute_force(std::vector<int> &prices) {
    size_t start = 0;
    size_t end = 0;
    int sum = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) {
        ++end;
      } else {
        sum += (prices[end] - prices[start]);
        start = i;
        end = i;
      }
    }

    sum += (prices[end] - prices[start]);

    return sum;
  }

  int brute_force_1(std::vector<int> &prices) {
    int sum = 0;
    const auto size = prices.size();
    for (size_t i = 1; i < size; ++i) {
      if (prices[i] > prices[i - 1]) {
        sum += (prices[i] - prices[i - 1]);
      }
    }

    return sum;
  }
};
// @lc code=end

TEST_CASE("best_time_to_buy_and_sell_stock_ii") {
  Solution sl;
  CHECK(sl.maxProfit(case_1) == 7);
  CHECK(sl.maxProfit(case_2) == 4);
  CHECK(sl.maxProfit(case_3) == 0);
}
