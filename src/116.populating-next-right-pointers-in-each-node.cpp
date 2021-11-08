/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

#include <map>
#include <vector>

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    traverse(root, 0);
    for (auto &pair : nodes) {
      auto vec = pair.second;
      auto it = vec.begin();
      while (it != vec.end()) {
        auto next = it + 1;
        if (next != vec.end()) {
          (*it)->next = *(next);
        } else {
          (*it)->next = nullptr;
        }
        ++it;
      }
    }

    return root;
  }

private:
  void traverse(Node *node, size_t level) {
    if (!node) {
      return;
    }
    nodes[level].push_back(node);
    traverse(node->left, level + 1);
    traverse(node->right, level + 1);
  }

private:
  std::map<size_t, std::vector<Node *>> nodes;
};
// @lc code=end

int main(int argc, char **argv) {
  Solution sl;
  {
    auto root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    sl.connect(root);
  }
}