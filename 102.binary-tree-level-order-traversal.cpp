/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

#include <queue>
#include <utility>
#include <vector>

using std::deque;
using std::pair;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }

    vector<vector<int>> ret;
    vector<int> group;
    int current_level = 0;
    deque<pair<TreeNode *, int>> nodes;
    nodes.push_back({root, current_level});
    while (!nodes.empty()) {
      const auto node = nodes.front();
      nodes.pop_front();

      if (current_level != node.second) {
        current_level = node.second;
        ret.push_back(group);
        group.clear();
      }

      group.push_back(node.first->val);
      if (node.first->left) {
        nodes.push_back({node.first->left, node.second + 1});
      }

      if (node.first->right) {
        nodes.push_back({node.first->right, node.second + 1});
      }
    }

    if (!group.empty()) {
      ret.push_back(group);
    }

    return ret;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution sl;
  {
    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    sl.levelOrder(root);
  }

  {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    sl.levelOrder(root);
  }
}
