/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
  TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    if(root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
  }
};

// Accepted
// 36/36 cases passed (36 ms)
// Your runtime beats 95.42 % of cpp submissions
// Your memory usage beats 93.48 % of cpp submissions (34.7 MB)
// @lc code=end

