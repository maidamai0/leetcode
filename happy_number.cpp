#include <iostream>
#include <set>
#include <vector>

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

auto main() -> int {
  Solution solution;

  for (int i = 0; i < 1000; i++) {
    std::boolalpha(std::cout);
    std::cout << i << " is happy?" << solution.isHappy(i) << std::endl;
  }
}