/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.28%)
 * Likes:    9136
 * Dislikes: 903
 * Total Accepted:    1.7M
 * Total Submissions: 3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a sorted list. The list
 * should be made by splicing together the nodes of the first two lists.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [], l2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [], l2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both l1 and l2 are sorted in non-decreasing order.
 *
 *
 */
#include "common/common.hpp"
#include "doctest/doctest.h"

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    auto* current = &dummy;
    while (l1 && l2) {
      if (l1->val > l2->val) {
        current->next = l2;
        l2 = l2->next;
      } else {
        current->next = l1;
        l1 = l1->next;
      }
      current = current->next;
    }

    if (l1) {
      current->next = l1;
    } else {
      current->next = l2;
    }

    return dummy.next;
  }
};
// @lc code=end
TEST_CASE("21. merge-two-sorted-lists") {
  Solution s;
  {
    auto* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    auto* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto* ans = s.mergeTwoLists(l1, l2);
    CHECK(ans->val == 1);
    CHECK(ans->next->val == 1);
    CHECK(ans->next->next->val == 2);
    CHECK(ans->next->next->next->val == 3);
    CHECK(ans->next->next->next->next->val == 4);
    CHECK(ans->next->next->next->next->next->val == 4);
    CHECK(ans->next->next->next->next->next->next == nullptr);
  }

  {
    ListNode* l1 = nullptr;
    auto l2 = new ListNode(0);
    auto ans = s.mergeTwoLists(l1, l2);
    CHECK(ans->val == 0);
    CHECK(ans->next == nullptr);
  }
}