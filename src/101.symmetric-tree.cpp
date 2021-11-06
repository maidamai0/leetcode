/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

#include "common/common.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <ostream>

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
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }

    std::list<TreeNode *> left_nodes;
    traverse_left_first(root->left, left_nodes);

    std::list<TreeNode *> right_nodes;
    traverse_right_first(root->right, right_nodes);

    return std::equal(left_nodes.begin(), left_nodes.end(), right_nodes.begin(),
                      [](TreeNode *left, TreeNode *right) {
                        // std::cout << left << " vs " << right << std::endl;
                        // all nullptr
                        if (left == right) {
                          return true;
                        }

                        // only one is nullptr
                        if (!left || !right) {
                          return false;
                        }

                        if (left->val == right->val) {
                          return true;
                        }

                        return false;
                      });

    std::cout << std::endl;
  }

  void traverse_left_first(TreeNode *node, std::list<TreeNode *> &nodes) {
    nodes.push_back(node);
    if (!node) {
      return;
    }

    traverse_left_first(node->left, nodes);
    traverse_left_first(node->right, nodes);
  }

  void traverse_right_first(TreeNode *node, std::list<TreeNode *> &nodes) {
    nodes.push_back(node);
    if (!node) {
      return;
    }

    traverse_right_first(node->right, nodes);
    traverse_right_first(node->left, nodes);
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution sl;
  {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    sl.isSymmetric(root);
  }

  //   std::cout << std::endl;

  {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    sl.isSymmetric(root);
  }
}