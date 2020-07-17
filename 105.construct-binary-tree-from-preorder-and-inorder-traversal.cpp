/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

#include "common/common.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;

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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build_tree(preorder, 0, preorder.size() - 1, inorder, 0,
                      inorder.size() - 1);
  }

  TreeNode *build_tree(const vector<int> &preorder, const int ps, const int pe,
                       const vector<int> &inorder, const int is, const int ie) {
    if (ps > pe) {
      return nullptr;
    }

    auto root = new TreeNode(preorder[ps]);
    auto pos = 0;
    for (int i = is; i <= ie; ++i) {
      if (inorder[i] == root->val) {
        pos = i;
        break;
      }
    }

    root->left =
        build_tree(preorder, ps + 1, ps + pos - is, inorder, is, pos - 1);

    root->right =
        build_tree(preorder, pe - ie + pos + 1, pe, inorder, pos + 1, ie);

    return root;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution sl;
  {
    auto preorder = std::vector<int>{3, 9, 20, 15, 7};
    auto inorder = std::vector<int>{9, 3, 15, 20, 7};
    sl.buildTree(preorder, inorder);
  }
}