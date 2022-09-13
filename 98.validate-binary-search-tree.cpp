/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
class Solution {
  int prev;
  bool hasPrev = false;
  
public:
  bool isValidBST(TreeNode* root) {
    if(!root) return true;
    if(!isValidBST(root->left)) return false;
    if(!hasPrev) {
      prev = root->val;
      hasPrev = true;
    } else {
      if(root->val <= prev) return false;
      prev = root->val;
    }
    return isValidBST(root->right);
  }
};

// Accepted
// 80/80 cases passed (24 ms)
// Your runtime beats 30.66 % of cpp submissions
// Your memory usage beats 30.71 % of cpp submissions (21.7 MB)
// @lc code=end

