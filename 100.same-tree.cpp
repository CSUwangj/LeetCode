/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

// Accepted
// 60/60 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 48.63 % of cpp submissions (10 MB)
// @lc code=end

