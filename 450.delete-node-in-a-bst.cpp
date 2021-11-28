/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
  void rebuildFromLeft(TreeNode *root) {
    if(!root->left->left && !root->left->right) {
      root->val = root->left->val;
      root->left = nullptr;
      return;
    }
    TreeNode *cur = root->left;
    if(cur->right) {
      TreeNode *parent;
      while(cur->right) {
        parent = cur;
        cur = cur->right;
      }
      root->val = cur->val;
      if(!cur->left) {
        parent->right = nullptr;
      } else {
        rebuildFromLeft(cur);
      }
    } else {
      root->val = cur->val;
      rebuildFromLeft(cur);
    }
  }
  
  void rebuildFromRight(TreeNode *root) {
    if(!root->right->left && !root->right->right) {
      root->val = root->right->val;
      root->right = nullptr;
      return;
    }
    TreeNode *cur = root->right;
    if(cur->left) {
      TreeNode *parent;
      while(cur->left) {
        parent = cur;
        cur = cur->left;
      }
      root->val = cur->val;
      if(cur->right) {
        rebuildFromRight(cur);
      } else {
        parent->left = nullptr;
      }
    } else {
      root->val = cur->val;
      rebuildFromRight(cur);
    }
  }
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode *cur = root;
    TreeNode *parent = nullptr;
    while(cur && cur->val != key) {
      parent = cur;
      if(key > cur->val) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }
    if(!cur) return root;
    if(!cur->left && !cur->right) {
      if(!parent) return nullptr;
      if(parent->left == cur) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
      return root;
    }
    if(cur->left) {
      rebuildFromLeft(cur);
    } else {
      rebuildFromRight(cur);
    }
    return root;
  }
};

// Accepted
// 91/91 cases passed (69 ms)
// Your runtime beats 5.07 % of cpp submissions
// Your memory usage beats 30.07 % of cpp submissions (32.7 MB)
// @lc code=end
