/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (44.99%)
 * Likes:    9266
 * Dislikes: 397
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 *
 *
 * Example 2:
 *
 *
 * Input: lists = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: lists = [[]]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length won't exceed 10^4.
 *
 *
 */
#include <algorithm>

#include "common/common.hpp"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    auto* cur = &dummy;
    while (true) {
      auto min_element = std::min_element(
          lists.begin(), lists.end(), [](const ListNode* a, const ListNode* b) {
            if (!a) {
              return false;
            }

            if (!b) {
              return true;
            }

            return a->val < b->val;
          });

      if (min_element == lists.end() || !*min_element) {
        break;
      }

      cur->next = *min_element;
      cur = cur->next;
      *min_element = (*min_element)->next;
    }
    cur->next = nullptr;
    return dummy.next;
  }
};
// @lc code=end

TEST_CASE("23. merge-k-sorted-lists") {
  Solution s;
  {
    auto* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    auto* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto* l3 = new ListNode(2, new ListNode(6));
    auto ls = vector<ListNode*>{l1, l2, l3};
    auto* ans = s.mergeKLists(ls);
    CHECK(ans->val == 1);
    CHECK(ans->next->val == 1);
    CHECK(ans->next->next->val == 2);
    CHECK(ans->next->next->next->val == 3);
    CHECK(ans->next->next->next->next->val == 4);
    CHECK(ans->next->next->next->next->next->val == 4);
    CHECK(ans->next->next->next->next->next->next->val == 5);
    CHECK(ans->next->next->next->next->next->next->next->val == 6);
    CHECK(ans->next->next->next->next->next->next->next->next == nullptr);
  }

  {
    vector<ListNode*> ls;
    auto ans = s.mergeKLists(ls);
    CHECK(ans == nullptr);
  }

  {
    auto* l1 = new ListNode(1);
    auto* l2 = new ListNode(1);
    auto* l3 = new ListNode(1);
    auto ls = vector<ListNode*>{l1, l2, l3};
    auto* ans = s.mergeKLists(ls);
    CHECK(ans->val == 1);
    CHECK(ans->next->val == 1);
    CHECK(ans->next->next->val == 1);
    CHECK(ans->next->next->next == nullptr);
  }

  {
    auto ls = vector<ListNode*>{nullptr};
    auto* ans = s.mergeKLists(ls);
    CHECK(ans == nullptr);
  }
}