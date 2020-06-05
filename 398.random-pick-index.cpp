/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

#include <algorithm>
#include <cstdlib>
#include <vcruntime.h>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  Solution(vector<int> &nums) : nums_(nums) {}

  int pick(int target) {
    std::vector<size_t> matched;
    for (size_t i = 0; i < nums_.size(); ++i) {
      if (nums_[i] == target) {
        matched.push_back(i);
      }
    }

    const auto range = matched.size();
    return matched[std::rand() % range];
  }

private:
  const std::vector<int> &nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
