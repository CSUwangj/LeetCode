/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int sum = 0;
  void traversal(TreeNode *root) {
    if(!root) return;
    traversal(root->right);
    root->val += sum;
    sum = root->val;
    traversal(root->left);
  }
public:
  TreeNode* convertBST(TreeNode* root) {
    traversal(root);
    return root;
  }
};

// Accepted
// 215/215 cases passed (38 ms)
// Your runtime beats 83.38 % of cpp submissions
// Your memory usage beats 12.35 % of cpp submissions (33.6 MB)
// @lc code=end

