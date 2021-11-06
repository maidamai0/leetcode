/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

#include <algorithm>
#include <vector>

#include "common/common.hpp"
#include "doctest/doctest.h"

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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    return build_tree(inorder, 0, inorder.size(), postorder, 0,
                      postorder.size());
  }

private:
  /**
   * @brief build tree
   *
   * @param inorder       inorder tree value
   * @param is            start of inorder
   * @param ie            end of inorder
   * @param postorder     poster order
   * @param ps            start of posterorder
   * @param pe            end of posterorder
   * @return TreeNode*
   */
  TreeNode *build_tree(const vector<int> &inorder, const int is, const int ie,
                       const vector<int> &postorder, const int ps,
                       const int pe) {
    // last value of postorder is root
    // 然后从inroder中找到mid，将其分割成为两部分，左边作为mid的左子树，右边作为mid的右子树
    // tree:     8 4 10 3 6 9 11
    // Inorder   [3 4 6] 8 [9 10 11]
    // postorder [3 6 4]   [9 11 10] 8

    if (is >= ie || ps >= pe)
      return nullptr;

    const auto mid = postorder[pe - 1];

    const auto f = find(inorder.begin() + is, inorder.begin() + ie, mid);

    const auto dis = f - inorder.begin() - is;

    auto *root = new TreeNode(mid);
    root->left = build_tree(inorder, is, is + dis, postorder, ps, ps + dis);
    root->right =
        build_tree(inorder, is + dis + 1, ie, postorder, ps + dis, pe - 1);

    return root;
  }
};
// @lc code=end
