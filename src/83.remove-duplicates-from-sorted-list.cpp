/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (47.83%)
 * Likes:    3596
 * Dislikes: 165
 * Total Accepted:    713.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]'
 *
 * Given the head of a sorted linked list, delete all duplicates such that each
 * element appears only once. Return the linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,1,2]
 * Output: [1,2]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
      if (cur->next->val == cur->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }

    return head;
  }
};
// @lc code=end

TEST_CASE("83.remove-duplicates-from-sorted-list") {
  Solution s;
  {
    auto head = new ListNode(1, new ListNode(1, new ListNode(2)));
    auto* ans = s.deleteDuplicates(head);
    CHECK(ans->val == 1);
    CHECK(ans->next->val == 2);
    CHECK(ans->next->next == nullptr);
  }

  {
    auto head = new ListNode(
        1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    auto* ans = s.deleteDuplicates(head);
    CHECK(ans->val == 1);
    CHECK(ans->next->val == 2);
    CHECK(ans->next->next->val == 3);
    CHECK(ans->next->next->next == nullptr);
  }
}