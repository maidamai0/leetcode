/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.14%)
 * Likes:    7527
 * Dislikes: 379
 * Total Accepted:    1.1M
 * Total Submissions: 3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
  }
};
// @lc code=end

TEST_CASE("19.remove-nth-node-from-end-of-list") {
  Solution s;
  {
    auto* head = new ListNode(
        1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto* res = s.removeNthFromEnd(head, 2);
    CHECK(res->val == 1);
    CHECK(res->next->val == 2);
    CHECK(res->next->next->val == 3);
    CHECK(res->next->next->next->val == 5);
  }

  {
    auto* head = new ListNode(1);
    auto* res = s.removeNthFromEnd(head, 1);
    CHECK(res == nullptr);
  }

  {
    auto* head = new ListNode(1, new ListNode(2));
    auto* res = s.removeNthFromEnd(head, 1);
    CHECK(res->val == 1);
  }
}