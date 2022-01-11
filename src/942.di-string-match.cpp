/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 *
 * https://leetcode.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (75.00%)
 * Likes:    1451
 * Dislikes: 569
 * Total Accepted:    95.4K
 * Total Submissions: 127.2K
 * Testcase Example:  '"IDID"'
 *
 * A permutation perm of n + 1 integers of all the integers in the range [0, n]
 * can be represented as a string s of length n where:
 *
 *
 * s[i] == 'I' if perm[i] < perm[i + 1], and
 * s[i] == 'D' if perm[i] > perm[i + 1].
 *
 *
 * Given a string s, reconstruct the permutation perm and return it. If there
 * are multiple valid permutations perm, return any of them.
 *
 *
 * Example 1:
 * Input: s = "IDID"
 * Output: [0,4,1,3,2]
 * Example 2:
 * Input: s = "III"
 * Output: [0,1,2,3]
 * Example 3:
 * Input: s = "DDI"
 * Output: [3,2,0,1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either 'I' or 'D'.
 *
 *
 */
#include "common/common.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> diStringMatch(string s) {
    int min = 0;
    int max = s.size();
    vector<int> res;
    for (int i = 0; i <= s.size(); i++) {
      if (s[i] == 'I') {
        res.push_back(min++);
      } else {
        res.push_back(max--);
      }
    }

    return res;
  }
};
// @lc code=end

TEST_CASE("example 1") {
  Solution s;
  CHECK(s.diStringMatch("IDID") == std::vector<int>{0, 4, 1, 3, 2});
}

TEST_CASE("example 2") {
  Solution s;
  CHECK(s.diStringMatch("III") == std::vector<int>{0, 1, 2, 3});
}

TEST_CASE("example 3") {
  Solution s;
  CHECK(s.diStringMatch("DDI") == std::vector<int>{3, 2, 0, 1});
}