/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
  int answer = 0;
  int solve(TreeNode *root, bool left) {
    if(!root) return 0;
    int r = solve(root->right, false);
    int l = solve(root->left, true);
    answer = max(answer, left + r);
    answer = max(answer, !left + l);
    if(left) return 1 + r;
    else return 1 + l;
  }
public:
  int longestZigZag(TreeNode* root) {
    solve(root->left, true);
    solve(root->right, false);
    return answer;
  }
};

// Accepted
// 58/58 cases passed (163 ms)
// Your runtime beats 84.67 % of cpp submissions
// Your memory usage beats 42.16 % of cpp submissions (100.4 MB)
// @lc code=end

