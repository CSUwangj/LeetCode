/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    vector<vector<int>> answer;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> curLevel;
      for(int i = 0; i < sz; ++i) {
        auto node = q.front();
        q.pop();
        curLevel.push_back(node->val);
        if(node->left) {
          q.push(node->left);
        }
        if(node->right) {
          q.push(node->right);
        }
      }
      answer.push_back(curLevel);
    }
    return answer;
  }
};
// @lc code=end

