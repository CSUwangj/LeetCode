/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
  int maxAncestorDiff(TreeNode* root, int mmin = INT_MAX, int mmax = INT_MIN) {
    // root node will not be nullptr by constraints
    if(!root) return mmax - mmin;
    mmin = min(mmin, root->val);
    mmax = max(mmax, root->val);
    return max(maxAncestorDiff(root->left, mmin, mmax), maxAncestorDiff(root->right, mmin, mmax));
  }
};

// Accepted
// 27/27 cases passed (4 ms)
// Your runtime beats 81.69 % of cpp submissions
// Your memory usage beats 74.27 % of cpp submissions (9.7 MB)
// @lc code=end
