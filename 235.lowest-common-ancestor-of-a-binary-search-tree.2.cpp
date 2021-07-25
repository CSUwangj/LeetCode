/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;
    if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    return root;
  }
};

// Accepted
// 27/27 cases passed (20 ms)
// Your runtime beats 99.02 % of cpp submissions
// Your memory usage beats 57.6 % of cpp submissions (23.3 MB)
// @lc code=end

