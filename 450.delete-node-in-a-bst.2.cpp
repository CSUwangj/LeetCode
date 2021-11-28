/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

// @lc code=start
static auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void rebuildFromLeft(TreeNode *root) {
    if(!root->left->right) {
      root->val = root->left->val;
      if(root->left->left) {
        rebuildFromLeft(root->left);
      } else {
        root->left = nullptr;
      }
      return;
    }
    TreeNode *cur = root->left;
    TreeNode *parent;
    while(cur->right) {
      parent = cur;
      cur = cur->right;
    }
    root->val = cur->val;
    if(cur->left) {
      rebuildFromLeft(cur);
    } else {
      parent->right = nullptr;
    }
  }
  
  void rebuildFromRight(TreeNode *root) {
    if(!root->right->left) {
      root->val = root->right->val;
      if(root->right->right) {
        rebuildFromRight(root->right);
      } else {
        root->right = nullptr;
      }
      return;
    }
    TreeNode *cur = root->right;
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
// 91/91 cases passed (36 ms)
// Your runtime beats 48.74 % of cpp submissions
// Your memory usage beats 30.07 % of cpp submissions (32.9 MB)
// @lc code=end
