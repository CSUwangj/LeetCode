/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(!root) return root;
    if(root->val < low) return trimBST(root->right, low, high);
    if(root->val > high) return trimBST(root->left, low, high);
    while(root->left && root->left->val < low) root->left = root->left->right;
    root->left = trimBST(root->left, low, high);
    while(root->right && root->right->val > high) root->right = root->right->left;
    root->right = trimBST(root->right, low, high);
    return root;
  }
};

// Accepted
// 78/78 cases passed (7 ms)
// Your runtime beats 99.34 % of cpp submissions
// Your memory usage beats 7.34 % of cpp submissions (24.1 MB)
// @lc code=end

