# Notes of my leetcode practicing

## Structure

Code is in the root path,every `cpp` file is a solution to a problem on [LeetCode](https://leetcode.com/)

Some notes about the sulution for particular problem are in the [notes](notes/README.md) directory.

## Tools I used

I use [vscode](https://code.visualstudio.com/) with [leetcode](https://marketplace.visualstudio.com/items?itemName=shengchen.vscode-leetcode) extension to do test and debug localy and submit I'm sure my solution works.

Usually I will make a brute force suluiton first and make more optimization veriosns.

Take an example:

```cpp
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
```

## Test framework

I personally like open source,modern,beautiful and lightweight tools.[doctest](https://github.com/onqtam/doctest) is my choice for testing.
