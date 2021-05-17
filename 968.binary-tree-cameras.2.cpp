/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
  unordered_set<TreeNode*> covered{nullptr};
  int answer = 0;
  void solve(TreeNode *cur, TreeNode *par = nullptr) {
    if(!cur) return;
    solve(cur->left);
    solve(cur->right);
    if(par == nullptr && !covered.count(cur) || !covered.count(cur->left) || !covered.count(cur->right)) {
      answer += 1;
      covered.insert(cur);
      covered.insert(par);
      covered.insert(cur->left);
      covered.insert(cur->right);
    }
  }
public:
  int minCameraCover(TreeNode* root) {
    solve(root);
    return answer;
  }
};
// @lc code=end

