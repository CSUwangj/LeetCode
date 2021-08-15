/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(!root) return nullptr;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if(root->val == target && !root->left && !root->right) return nullptr;
    return root;
  }
};

// Accepted
// 50/50 cases passed (12 ms)
// Your runtime beats 88.29 % of cpp submissions
// Your memory usage beats 14.7 % of cpp submissions (22 MB)
// @lc code=end

