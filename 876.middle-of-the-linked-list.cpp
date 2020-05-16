/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

#include <initializer_list>
#include <vector>

#include "doctest/doctest.h"

/**
 * Definition for singly-linked list.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  // user defined
  ListNode(std::initializer_list<int> values) {
    auto is_head = true;
    ListNode **tail = nullptr;
    for (const auto value : values) {
      if (is_head) {
        is_head = false;
        val = value;
        next = nullptr;
        tail = &next;
      } else {
        *tail = new ListNode(value);
        tail = &((*tail)->next);
      }
    }
  }
};

// @lc code=start
class Solution {
public:
  ListNode *middleNode(ListNode *head) { return brute_force(head); }

private:
  ListNode *brute_force(ListNode *head) {
    std::vector<ListNode *> nodes;

    while (head) {
      nodes.push_back(head);
      head = head->next;
    }

    return nodes[nodes.size() / 2];
  }
};
// @lc code=end

ListNode *case_1 = nullptr;
ListNode *case_2 = nullptr;

void prepare_case() {
  static bool prepared = false;
  if (!prepared) {
    // case 1
    case_1 = new ListNode({1, 2, 3, 4, 5});
    case_2 = new ListNode({1, 2, 3, 4, 5, 6});
  }
  prepared = true;
}

TEST_CASE("middle_of_the_linked_list") {
  Solution sl;
  prepare_case();
  CHECK(sl.middleNode(case_1)->val == 3);
  CHECK(sl.middleNode(case_2)->val == 4);
}