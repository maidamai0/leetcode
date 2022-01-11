/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (41.26%)
 * Likes:    3923
 * Dislikes: 144
 * Total Accepted:    588.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Given the head of a linked list and an integer val, remove all the nodes of
 * the linked list that has Node.val == val, and return the new head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [], val = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 10^4].
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
 *
 *
 */
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    auto* cur = &dummy;
    cur->next = head;
    while (cur->next) {
      if (cur->next->val == val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return dummy.next;
  }

 private:
  ListNode* removeElements1(ListNode* head, int val) {
    ListNode dummy(0);
    auto* new_head = &dummy;
    while (head) {
      if (head->val != val) {
        new_head->next = head;
        new_head = new_head->next;
      }
      head = head->next;
    }
    new_head->next = nullptr;
    return dummy.next;
  }
};
// @lc code=end

TEST_CASE("203. Remove Linked List Elements") {
  Solution s;
  {
    auto head = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                6, new ListNode(
                       3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    auto res = s.removeElements(head, 6);
    CHECK(res->val == 1);
    CHECK(res->next->val == 2);
    CHECK(res->next->next->val == 3);
    CHECK(res->next->next->next->val == 4);
    CHECK(res->next->next->next->next->val == 5);
    CHECK(res->next->next->next->next->next == nullptr);
  }

  {
    ListNode* head = nullptr;
    auto* ans = s.removeElements(head, 1);
    CHECK(ans == nullptr);
  }

  {
    auto head =
        new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    auto res = s.removeElements(head, 7);
    CHECK(res == nullptr);
  }
}