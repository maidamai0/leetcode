/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 *
 * https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
 *
 * algorithms
 * Easy (81.81%)
 * Likes:    1684
 * Dislikes: 84
 * Total Accepted:    217.5K
 * Total Submissions: 265.9K
 * Testcase Example:  '[1,0,1]'
 *
 * Given head which is a reference node to a singly-linked list. The value of
 * each node in the linked list is either 0 or 1. The linked list holds the
 * binary representation of a number.
 *
 * Return the decimal value of the number in the linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,0,1]
 * Output: 5
 * Explanation: (101) in base 2 = (5) in base 10
 *
 *
 * Example 2:
 *
 *
 * Input: head = [0]
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1]
 * Output: 1
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
 * Output: 18880
 *
 *
 * Example 5:
 *
 *
 * Input: head = [0,0]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * The Linked List is not empty.
 * Number of nodes will not exceed 30.
 * Each node's value is either 0 or 1.
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
  int getDecimalValue(ListNode* head) {
    int sum = 0;
    while (head) {
      sum = (sum << 1) + head->val;
      head = head->next;
    }

    return sum;
  }
};
// @lc code=end

TEST_CASE("1290.convert-binary-number-in-a-linked-list-to-integer") {
  Solution s;
  {
    auto* head = CreateListNode(1, 0, 1);
    CHECK(s.getDecimalValue(head) == 5);
  }

  {
    auto* head = CreateListNode(0);
    CHECK(s.getDecimalValue(head) == 0);
  }

  {
    auto* head = CreateListNode(1);
    CHECK(s.getDecimalValue(head) == 1);
  }

  {
    auto head = CreateListNode(0, 1);
    CHECK(s.getDecimalValue(head) == 1);
  }

  {
    auto* head = CreateListNode(1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0);
    CHECK(s.getDecimalValue(head) == 18880);
  }
}