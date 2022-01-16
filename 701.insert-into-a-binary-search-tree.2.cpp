/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode *cur = root;
    while(true) {
      if(val > cur->val) {
        if(!cur->right) {
          cur->right = new TreeNode(val);
          break;
        } else {
          cur = cur->right;
        }
      } else {
        if(!cur->left) {
          cur->left = new TreeNode(val);
          break;
        } else {
          cur = cur->left;
        }
      }
    }
    return root;
  }
};

// Accepted
// 35/35 cases passed (140 ms)
// Your runtime beats 20.03 % of cpp submissions
// Your memory usage beats 49.59 % of cpp submissions (57.1 MB)
// @lc code=end
