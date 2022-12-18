/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
  int answer = INT_MIN;
  int solve(TreeNode* root) {
    if(!root) return 0;
    int maxLeft = solve(root->left);
    int maxRight = solve(root->right);
    int val = root->val;
    if(maxLeft > 0) val += maxLeft;
    if(maxRight > 0) val += maxRight;
    answer = max(answer, val);
    return (maxLeft < 0 && maxRight < 0) ? root->val :
           maxLeft > maxRight ? root->val + maxLeft :
                                root->val + maxRight;
  }
public:
  int maxPathSum(TreeNode* root) {
    solve(root);
    return answer;
  }
};

// Accepted
// 94/94 cases passed (62 ms)
// Your runtime beats 27.91 % of cpp submissions
// Your memory usage beats 35.19 % of cpp submissions (27.7 MB)
// @lc code=end

