/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 *
 * https://leetcode.com/problems/check-if-n-and-its-double-exist/description/
 *
 * algorithms
 * Easy (35.50%)
 * Likes:    608
 * Dislikes: 85
 * Total Accepted:    148.6K
 * Total Submissions: 418.8K
 * Testcase Example:  '[10,2,5,3]'
 *
 * Given an array arr of integers, check if there exists two integers N and M
 * such that N is the double of M ( i.e. N = 2 * M).
 *
 * More formally check if there exists two indices i and j such that :
 *
 *
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [10,2,5,3]
 * Output: true
 * Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [7,1,14,11]
 * Output: true
 * Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [3,1,7,11]
 * Output: false
 * Explanation: In this case does not exist N and M, such that N = 2 * M.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    std::unordered_set<int> s;
    for (const auto& i : arr) {
      if (s.find(i * 2) != s.end()) {
        return true;
      }

      if (i % 2 == 0 && s.find(i / 2) != s.end()) {
        return true;
      }

      s.insert(i);
    }

    return false;
  }
};
// @lc code=end
TEST_CASE("1346 check-if-n-and-its-double-exist") {
  Solution s;
  {
    vector<int> arr{10, 2, 5, 3};
    REQUIRE(s.checkIfExist(arr) == true);
  }
  {
    vector<int> arr{7, 1, 14, 11};
    REQUIRE(s.checkIfExist(arr) == true);
  }
  {
    vector<int> arr{3, 1, 7, 11};
    REQUIRE(s.checkIfExist(arr) == false);
  }
}