#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    std::map<Node *, Node *> my_map;
    auto original_head = head;
    auto copy_head = new Node(original_head->val);
    my_map[original_head] = copy_head;
    my_map[nullptr] = nullptr;

    auto copy = copy_head;
    while (original_head->next) {
      copy->next = new Node(original_head->next->val);
      my_map[original_head->next] = copy->next;

      original_head = original_head->next;
      copy = copy->next;
    }

    original_head = head;
    copy = copy_head;

    while (copy) {
      copy->random = my_map[original_head->random];
      copy = copy->next;
      original_head = original_head->next;
    }

    return copy_head;
  }

  void reverseString(vector<char> &s) {
    auto left = 0;
    auto right = s.size() - 1;

    while (left < right) {
      std::swap(s[left], s[right]);
      ++left;
      --right;
    }
  }

  ListNode *swapPairs(ListNode *head) {
    // empty
    if (!head) {
      return head;
    }

    // only one element
    if (!head->next) {
      return head;
    }

    auto first = head;
    auto second = head->next;

    first->next = swapPairs(second->next);
    second->next = first;

    return second;
  }

  ListNode *reverseList(ListNode *head) {
    return reverse_list_recursive(head, nullptr);
  }

  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root) {
      return nullptr;
    }

    if (root->val == val) {
      return root;
    }

    if (root->val > val) {
      return searchBST(root->right, val);
    } else {
      return searchBST(root->left, val);
    }
  }

  vector<TreeNode *> generateTrees(int n) {}

  vector<int> getRow(int rowIndex) {
    if (rowIndex == 0) {
      return std::vector<int>{1};
    }

    if (rowIndex == 1) {
      return std::vector<int>{1, 1};
    }

    auto last = getRow(rowIndex - 1);
    std::vector<int> ret;
    ret.reserve(rowIndex + 1);

    ret.push_back(1);
    for (int i = 0; i < last.size() - 1; ++i) {
      ret.push_back(last[i] + last[i + 1]);
    }
    ret.push_back(1);

    return ret;
  }

  int climbStairs(int n) {
    if (n == 0) {
      return 1;
    }

    if (n == 1) {
      return 1;
    }

    int value0 = 1;
    int value1 = 1;
    int value2 = 0;

    for (int i = 2; i < n + 1; ++i) {
      value2 = value0 + value1;
      value0 = value1;
      value1 = value2;
    }

    return value2;
  }

  int maxDepth(TreeNode *root) { return max_depth(0, root); }
  double myPow(double x, int n) {
    if (x == 0.0 || x == 1.0) {
      return x;
    }

    if (n == 0) {
      return 1;
    }

    return (n / 2 == 0) ? myPow(x * x, n / 2) : x * pow(x * x, n / 2);
  }
  int kthGrammar(int N, int K) {
    if (N == 1) {
      return 0;
    }

    int n = kthGrammar(N - 1, (K + 1) / 2);
    std::vector<int> temp(2, 0);
    if (n == 0) {
      temp[1] = 1;
    } else {
      temp[0] = 1;
    }

    if (K % 2) {
      return temp[0];
    } else {
      return temp[1];
    }
  }

private:
  ListNode *reverse_list_recursive(ListNode *next_node, ListNode *head) {
    if (!next_node) {
      return head;
    }

    auto next = next_node->next;
    next_node->next = head;
    return reverse_list_recursive(next, next_node);
  }

  int max_depth(int depth, TreeNode *root) {
    if (!root) {
      return depth;
    }

    return std::max(max_depth(depth + 1, root->left),
                    max_depth(depth + 1, root->right));
  }

  vector<TreeNode *> generate_binary_tree(int from, int to) {
    if (from > to) {
      return {nullptr};
    }

    if (!cache[from][to].empty()) {
      return cache[from][to];
    }

    vector<TreeNode *> nodes;
    for (int i = from; i <= to; ++i) {
      for (const auto &left : generate_binary_tree(from, i - 1)) {
        for (const auto &right : generate_binary_tree(i + 1, to)) {
          nodes.push_back(new TreeNode(i, left, right));
        }
      }
    }

    cache[from][to] = nodes;
    return nodes;
  }

private:
  std::vector<int> nums_;
  unordered_map<int, unordered_map<int, vector<TreeNode *>>> cache;
};

void print_reverse_string(const char *str) {
  if (*str == '\0') {
    return;
  }
  print_reverse_string(str + 1);
  std::cout << *str << std::endl;
}

int main(int argc, char **argv) {
  Solution sln;
  sln.kthGrammar(30, 434991989);
}