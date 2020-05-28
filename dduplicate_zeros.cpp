#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  void duplicateZeros(vector<int> &&arr) {
    int zero_cnt = 0;
    for (const auto &n : arr) {
      if (n == 0) {
        ++zero_cnt;
      }
    }

    auto index = arr.size() - 1;
    auto index_1 = arr.size() + zero_cnt - 1;
    while (index <= 200000) {
      if (arr[index] == 0) {

        if (index_1 < arr.size()) {
          arr[index_1] = 0;
        }

        --index_1;
        if (index_1 < arr.size()) {
          arr[index_1] = 0;
        }

      } else if (index_1 < arr.size()) {
        arr[index_1] = arr[index];
      }

      --index;
      --index_1;
    }
  }
};

auto main(int argc, char **argv) -> int {
  Solution sln;
  sln.duplicateZeros({1, 0, 2, 3, 0, 4, 5, 0});
}
