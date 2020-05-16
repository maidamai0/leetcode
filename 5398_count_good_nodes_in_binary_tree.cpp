#include <algorithm>

/**
 * Definition for a binary tree node.
 */
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
  int goodNodes(TreeNode *root) {
    trans(root, root->val);
    return cnt_;
  }

private:
  void trans(TreeNode *node, int max) {

    if (node->val >= max) {
      ++cnt_;
      max = node->val;
    }

    if (node->left) {
      trans(node->left, max);
    }

    if (node->right) {
      trans(node->right, max);
    }
  }

private:
  int cnt_ = 0;
};

int main() {}