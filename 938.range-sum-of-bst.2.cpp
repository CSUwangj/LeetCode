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
    int result;
    if(root->val > high) result = rangeSumBST(root->left, low, high);
    else if(root->val < low) result = rangeSumBST(root->right, low, high);
    else result = root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    // weird operation, copied from quickest solution
    root->left = root->right = nullptr;
    return result;
  }
};

// Accepted
// 41/41 cases passed (60 ms)
// Your runtime beats 99.88 % of cpp submissions
// Your memory usage beats 99.68 % of cpp submissions (51.7 MB)
// @lc code=end
