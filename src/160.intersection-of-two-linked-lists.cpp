/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (47.49%)
 * Likes:    7105
 * Dislikes: 742
 * Total Accepted:    792.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3'
 *
 * Given the heads of two singly linked-lists headA and headB, return the node
 * at which the two lists intersect. If the two linked lists have no
 * intersection at all, return null.
 *
 * For example, the following two linked lists begin to intersect at node c1:
 *
 * The test cases are generated such that there are no cycles anywhere in the
 * entire linked structure.
 *
 * Note that the linked lists must retain their original structure after the
 * function returns.
 *
 * Custom Judge:
 *
 * The inputs to the judge are given as follows (your program is not given
 * these inputs):
 *
 *
 * intersectVal - The value of the node where the intersection occurs. This is
 * 0 if there is no intersected node.
 * listA - The first linked list.
 * listB - The second linked list.
 * skipA - The number of nodes to skip ahead in listA (starting from the head)
 * to get to the intersected node.
 * skipB - The number of nodes to skip ahead in listB (starting from the head)
 * to get to the intersected node.
 *
 *
 * The judge will then create the linked structure based on these inputs and
 * pass the two heads, headA and headB to your program. If you correctly return
 * the intersected node, then your solution will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA =
 * 2, skipB = 3
 * Output: Intersected at '8'
 * Explanation: The intersected node's value is 8 (note that this must not be 0
 * if the two lists intersect).
 * From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as
 * [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are
 * 3 nodes before the intersected node in B.
 *
 *
 * Example 2:
 *
 *
 * Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3,
 * skipB = 1
 * Output: Intersected at '2'
 * Explanation: The intersected node's value is 2 (note that this must not be 0
 * if the two lists intersect).
 * From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as
 * [3,2,4]. There are 3 nodes before the intersected node in A; There are 1
 * node before the intersected node in B.
 *
 *
 * Example 3:
 *
 *
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB =
 * 2
 * Output: No intersection
 * Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it
 * reads as [1,5]. Since the two lists do not intersect, intersectVal must be
 * 0, while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes of listA is in the m.
 * The number of nodes of listB is in the n.
 * 0 <= m, n <= 3 * 10^4
 * 1 <= Node.val <= 10^5
 * 0 <= skipA <= m
 * 0 <= skipB <= n
 * intersectVal is 0 if listA and listB do not intersect.
 * intersectVal == listA[skipA] == listB[skipB] if listA and listB
 * intersect.
 *
 *
 *
 * Follow up: Could you write a solution that runs in O(n) time and use only
 * O(1) memory?
 */

#include "common/common.hpp"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
      return nullptr;
    }
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (p1 != p2) {
      p1 = p1 ? p1->next : headB;
      p2 = p2 ? p2->next : headA;
    }
    return p1;
  }
};
// @lc code=end
TEST_CASE("example 1") {
  ListNode *a = new ListNode(4);
  a->next = new ListNode(1);
  a->next->next = new ListNode(8);
  a->next->next->next = new ListNode(4);
  a->next->next->next->next = new ListNode(5);

  ListNode *b = new ListNode(5);
  b->next = new ListNode(6);
  b->next->next = new ListNode(1);
  b->next->next->next = a->next->next;
  Solution s;
  CHECK(s.getIntersectionNode(a, b) == a->next->next);
}

TEST_CASE("example 2") {
  ListNode *a = new ListNode(1);
  a->next = new ListNode(9);
  a->next->next = new ListNode(1);
  a->next->next->next = new ListNode(2);
  a->next->next->next->next = new ListNode(4);

  ListNode *b = new ListNode(3);
  b->next = a->next->next->next;
  Solution s;
  CHECK(s.getIntersectionNode(a, b) == a->next->next->next);
}