/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.26%)
 * Likes:    9236
 * Dislikes: 165
 * Total Accepted:    1.7M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
  ListNode* reverseList(ListNode* head) {
    ListNode* new_head = nullptr;
    while (head) {
      auto* next = head->next;
      head->next = new_head;
      new_head = head;
      head = next;
    }

    return new_head;
  }
};
// @lc code=end
TEST_CASE("reverse-linked-list") {
  auto s = new Solution();
  {
    auto* head = new ListNode(
        1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto* res = s->reverseList(head);
    CHECK(res->val == 5);
    CHECK(res->next->val == 4);
    CHECK(res->next->next->val == 3);
    CHECK(res->next->next->next->val == 2);
    CHECK(res->next->next->next->next->val == 1);
    CHECK(res->next->next->next->next->next == nullptr);
  }

  {
    auto* head = new ListNode(1, new ListNode(2));
    auto* res = s->reverseList(head);
    CHECK(res->val == 2);
    CHECK(res->next->val == 1);
    CHECK(res->next->next == nullptr);
  }

  {
    auto* head = new ListNode(1);
    auto* res = s->reverseList(head);
    CHECK(res->val == 1);
    CHECK(res->next == nullptr);
  }

  {
    ListNode* head = nullptr;
    auto* res = s->reverseList(head);
    CHECK(res == nullptr);
  }
}