/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (65.35%)
 * Likes:    1676
 * Dislikes: 1814
 * Total Accepted:    543.9K
 * Total Submissions: 830.8K
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 *
 *
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i if non of the above conditions are true.
 *
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0 && i % 5 == 0) {
        res.push_back("FizzBuzz");
      } else if (i % 3 == 0) {
        res.push_back("Fizz");
      } else if (i % 5 == 0) {
        res.push_back("Buzz");
      } else {
        res.push_back(to_string(i));
      }
    }
    return res;
  }
};
// @lc code=end
TEST_CASE("412.fizz-buzz") {
  Solution s;
  CHECK(s.fizzBuzz(3) == vector<string>{"1", "2", "Fizz"});
  CHECK(s.fizzBuzz(5) == vector<string>{"1", "2", "Fizz", "4", "Buzz"});
  CHECK(s.fizzBuzz(15) == vector<string>{"1", "2", "Fizz", "4", "Buzz", "Fizz",
                                         "7", "8", "Fizz", "Buzz", "11", "Fizz",
                                         "13", "14", "FizzBuzz"});
}