/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (41.23%)
 * Likes:    3893
 * Dislikes: 135
 * Total Accepted:    384.9K
 * Total Submissions: 930.4K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
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
    while (head && head->next && head->val == head->next->val) {
      auto val = head->val;
      while (head && head->val == val) {
        head = head->next;
      }
    }

    if (!head) {
      return head;
    }

    ListNode* new_head = nullptr;
    auto* tail = head;
    auto* cur = head->next;

    while (cur && cur->next) {
      if (cur->val == cur->next->val) {
        const auto val = cur->val;
        while (cur && cur->val == val) {
          cur = cur->next;
        }
      } else {
        if (!new_head) {
          new_head = cur;
        }
        tail->next = cur;
        tail = tail->next;
        cur = cur->next;
      }
    }

    tail->next = cur;

    return head;
  }
};
// @lc code=end

TEST_CASE("82. remove-duplicates-from-sorted-list-ii") {
  Solution s;
  {
    auto* head = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                3, new ListNode(
                       3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
    auto* res = s.deleteDuplicates(head);
    CHECK(res->val == 1);
    CHECK(res->next->val == 2);
    CHECK(res->next->next->val == 5);
  }
  {
    auto* head = new ListNode(
        1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3)))));
    auto* res = s.deleteDuplicates(head);
    CHECK(res->val == 2);
    CHECK(res->next->val == 3);
    CHECK(res->next->next == nullptr);
  }

  {
    auto* head = new ListNode(1, new ListNode(1));
    auto* res = s.deleteDuplicates(head);
    CHECK(res == nullptr);
  }

  {
    auto* head =
        new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(2))));
    auto* res = s.deleteDuplicates(head);
    CHECK(res == nullptr);
  }

  {
    auto* head = new ListNode(1, new ListNode(2, new ListNode(2)));
    auto* res = s.deleteDuplicates(head);
    CHECK(res->val == 1);
    CHECK(res->next == nullptr);
  }
}