/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void flatten(TreeNode* root) {
    if(!root) return;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;
    while(cur) {
      if(!cur->left) {
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode *right = cur->left;
        while(right->right != nullptr && right->right != cur) {
          right = right->right;
        }
        if(right->right == cur) {
          right->right = cur->right;
          cur->right = cur->left;
          cur->left = nullptr;
          cur = right->right;
        } else {
          right->right = cur;
          cur = cur->left;
        }
      }
    }
  }
};
// @lc code=end

