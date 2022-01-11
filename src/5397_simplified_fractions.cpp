#include "common/common.hpp"

using std::string;
using std::vector;

class Solution {
public:
  vector<string> simplifiedFractions(int n) { return brute_force(n); }

private:
  vector<string> brute_force(const int n) {
    if (n == 1) {
      return {};
    }

    if (n == 2) {
      return {"1/2"};
    }

    std::vector<string> ret;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (has_common(j, i)) {
          continue;
        }
        std::stringstream ss;
        ss << j << "/" << i;
        ret.push_back(ss.str());
      }
    }

    return ret;
  }

  bool has_common(const int i, const int j) {
    for (int s = 2; s <= i; ++s) {
      if (!(i % s) && !(j % s)) {
        return true;
      }
    }

    return false;
  }
};

TEST_CASE("simplified_fractions") {
  Solution sl;

  sl.simplifiedFractions(2);
  sl.simplifiedFractions(3);
  sl.simplifiedFractions(4);
  sl.simplifiedFractions(6);
  sl.simplifiedFractions(1);
}