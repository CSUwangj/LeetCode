/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
  TreeNode* bstToGst(TreeNode* root) {
    int tmp = 0;
    traversal(root, tmp);
    return root;
  }
};

// Accepted
// 28/28 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 12.59 % of cpp submissions (8.2 MB)
// @lc code=end
