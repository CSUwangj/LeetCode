/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root) return 0;
    if(root->val > high) return rangeSumBST(root->left, low, high);
    if(root->val < low) return rangeSumBST(root->right, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
  }
};

// Accepted
// 41/41 cases passed (92 ms)
// Your runtime beats 99.56 % of cpp submissions
// Your memory usage beats 60.14 % of cpp submissions (64.6 MB)
// @lc code=end
