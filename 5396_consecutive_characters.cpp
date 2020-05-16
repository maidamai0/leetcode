#include <algorithm>
#include <array>
#include <string>

#include "doctest/doctest.h"

using std::string;

class Solution {
public:
  int maxPower(string s) { return brute_force(s); }

private:
  int brute_force(string &s) {
    int size = 1;
    int temp = 1;
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++temp;
      } else {
        size = std::max(size, temp);
        temp = 1;
      }
    }
    size = std::max(size, temp);

    return size;
  }
};

TEST_CASE("consecutive_characters") {
  Solution sl;

  CHECK(sl.maxPower("leetcode") == 2);
  CHECK(sl.maxPower("abbcccddddeeeeedcba") == 5);
  CHECK(sl.maxPower("triplepillooooow") == 5);
  CHECK(sl.maxPower("hooraaaaaaaaaaay") == 11);
  CHECK(sl.maxPower("tourist") == 1);
  CHECK(sl.maxPower("cc") == 2);
}