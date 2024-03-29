/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.16%)
 * Likes:    14649
 * Dislikes: 3217
 * Total Accepted:    2.3M
 * Total Submissions: 6.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto cur = new ListNode(0);
    auto res = cur;
    bool carry = false;

    while (l1 || l2) {
      int sum = 0;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      if (carry) {
        sum++;
        carry = false;
      }
      if (sum >= 10) {
        carry = true;
        sum -= 10;
      }
      cur->next = new ListNode(sum);
      cur = cur->next;
    }

    if (carry) {
      cur->next = new ListNode(1);
    }

    return res->next;
  }
};
// @lc code=end

TEST_CASE("2.add-two-numbers") {
  Solution sol;
  {
    auto* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    auto* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    auto res = sol.addTwoNumbers(l1, l2);
    CHECK(res->val == 7);
    CHECK(res->next->val == 0);
    CHECK(res->next->next->val == 8);
  }

  {
    auto* l1 = new ListNode(0);
    auto* l2 = new ListNode(0);
    auto res = sol.addTwoNumbers(l1, l2);
    CHECK(res->val == 0);
  }

  {
    auto* l1 = new ListNode(
        9,
        new ListNode(
            9,
            new ListNode(
                9, new ListNode(
                       9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    auto* l2 =
        new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    auto res = sol.addTwoNumbers(l1, l2);
    CHECK(res->val == 8);
    CHECK(res->next->val == 9);
    CHECK(res->next->next->val == 9);
    CHECK(res->next->next->next->val == 9);
    CHECK(res->next->next->next->next->val == 0);
    CHECK(res->next->next->next->next->next->val == 0);
    CHECK(res->next->next->next->next->next->next->val == 0);
    CHECK(res->next->next->next->next->next->next->next->val == 1);
  }
}