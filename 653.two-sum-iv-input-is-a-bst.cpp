/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
  TreeNode *leftTravel(TreeNode *root, int min) {
    if(!root) return root;
    TreeNode *left = root->left;
    while(left && left->val > min) {
      while(left->right && left->right != root) {
        left = left->right;
      }
      if(left->right == root) {
        left->right = nullptr;
        return root;
      } 
      left->right = root;
      root = root->left;
      left = root->left;
    }
    return root;
  }

  TreeNode *rightTravel(TreeNode *root, int max) {
    if(!root) return root;
    TreeNode *right = root->right;
    while(right && right->val < max) {
      while(right->left && right->left != root) {
        right = right->left;
      }
      if(right->left == root) {
        right->left = nullptr;
        return root;
      } 
      right->left = root;
      root = root->right;
      right = root->right;
    }
    return root;
  }
  TreeNode *copy(TreeNode *root) {
    if(!root) return root;
    TreeNode *newRoot = new TreeNode(root->val);
    newRoot->left = copy(root->left);
    newRoot->right = copy(root->right);
    return newRoot;
  }
public:
  bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    // comment line below, dump leetcode will RE
    root = copy(root);
    TreeNode *leftCur = leftTravel(root, INT_MIN);
    TreeNode *rightCur = rightTravel(root, INT_MAX);
    while(leftCur && rightCur && leftCur != rightCur) {
    int leftMin = leftCur->val;
    int rightMost = rightCur->val;
      int sum = leftCur->val + rightCur->val;
      if(sum == k) {
        return true;
      } else if (sum < k) {
        leftCur = leftTravel(leftCur->right, leftMin);
      } else {
        rightCur = rightTravel(rightCur->left, rightMost);
      }
    }
    return false;
  }
};

// Accepted
// 422/422 cases passed (52 ms)
// Your runtime beats 22.62 % of cpp submissions
// Your memory usage beats 12.33 % of cpp submissions (40.9 MB)
// @lc code=end

