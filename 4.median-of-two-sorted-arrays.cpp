/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <iterator>
#include <vcruntime.h>
#include <vector>

#include "doctest/doctest.h"

using namespace std;

// @lc code=start
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    return merge(nums1, nums2);
  }

private:
  double merge(const vector<int> &nums1, const vector<int> &nums2) {
    if (nums1.empty() && nums2.empty()) {
      return 0.0;
    } else if (nums1.empty()) {
      return get_median_from_sorted(nums2, nums2.size());
    } else if (nums2.empty()) {
      return get_median_from_sorted(nums1, nums1.size());
    }

    const auto size = nums1.size() + nums2.size();
    size_t index_1 = 0;
    size_t index_2 = 0;

    const auto merged_size = size / 2 + 1;
    std::vector<int> merged;
    merged.reserve(merged_size);

    for (size_t i = 0; i < merged_size; ++i) {
      if (index_1 >= nums1.size()) {
        append(merged, nums2, index_2);
        break;
      } else if (index_2 >= nums2.size()) {
        append(merged, nums1, index_1);
        break;
      }

      if (nums1[index_1] <= nums2[index_2]) {
        merged.push_back(nums1[index_1++]);
      } else {
        merged.push_back(nums2[index_2++]);
      }
    }
    return get_median_from_sorted(merged, size);
  }

  double get_median_from_sorted(const std::vector<int> &nums,
                                const size_t size) {
    const auto half = size / 2;
    if (size & 0x1) {
      return static_cast<double>(nums[half]);
    } else {
      return (static_cast<double>(nums[half]) +
              static_cast<double>(nums[half - 1])) /
             2;
    }
  }

  void append(std::vector<int> &dest, const std::vector<int> &src,
              size_t start = 0) {
    const auto size = dest.capacity();
    for (size_t i = dest.size(); i < size; ++i) {
      dest.push_back(src[start++]);
    }
  }
};
// @lc code=end

TEST_CASE("both empty") {
  Solution sol;
  auto nums1 = std::vector<int>{};
  auto nums2 = std::vector<int>{};
  CHECK(sol.findMedianSortedArrays(nums1, nums2) == 0.0);
}

TEST_CASE("single empty") {
  Solution sol;
  auto nums1 = std::vector<int>{};
  auto nums2 = std::vector<int>{1};
  CHECK(sol.findMedianSortedArrays(nums1, nums2) == 1.0);
}

TEST_CASE("odd") {
  Solution sol;
  auto nums1 = std::vector<int>{1, 3};
  auto nums2 = std::vector<int>{2};
  CHECK(sol.findMedianSortedArrays(nums1, nums2) == 2.0);
}

TEST_CASE("even") {
  Solution sol;
  {
    auto nums1 = std::vector<int>{1, 3};
    auto nums2 = std::vector<int>{2, 4};
    CHECK(sol.findMedianSortedArrays(nums1, nums2) == 2.5);
  }

  {
    auto nums1 = std::vector<int>{1, 2};
    auto nums2 = std::vector<int>{3, 4};
    CHECK(sol.findMedianSortedArrays(nums1, nums2) == 2.5);
  }

  {
    auto nums1 = std::vector<int>{1};
    auto nums2 = std::vector<int>{1};
    CHECK(sol.findMedianSortedArrays(nums1, nums2) == 1.0);
  }
}