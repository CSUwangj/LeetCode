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
  void traversal(TreeNode *root, int &sum) {
    if(!root) return;
    traversal(root->right, sum);
    root->val += sum;
    sum = root->val;
    traversal(root->left, sum);
  }
public:
  TreeNode* convertBST(TreeNode* root) {
    int tmp = 0;
    traversal(root, tmp);
    return root;
  }
};

// Accepted
// 215/215 cases passed (38 ms)
// Your runtime beats 83.38 % of cpp submissions
// Your memory usage beats 12.35 % of cpp submissions (33.6 MB)
// @lc code=end

