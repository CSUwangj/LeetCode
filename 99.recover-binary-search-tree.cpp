/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {    
  vector<TreeNode*> wrongNodes;
  void check(TreeNode* cur, TreeNode* prev) {
    if(prev && prev->val >= cur->val) {
      wrongNodes.push_back(prev);
      wrongNodes.push_back(cur);
    }
  }
public:
  void recoverTree(TreeNode* root) {
    TreeNode *cur = root, *prev = nullptr;
    while(cur) {
      if(!(cur->left)) {
        check(cur, prev);
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode *pred = cur->left;
        while(pred->right && pred->right != cur) pred = pred->right;
        if(pred->right) {
          pred->right = nullptr;
          check(cur, prev);
          prev = cur;
          cur = cur->right;
        } else {
          pred->right = cur;
          cur = cur->left;
        }
      }
    }
    swap(wrongNodes.front()->val, wrongNodes.back()->val);
  }
};

// Accepted
// 1919/1919 cases passed (20 ms)
// Your runtime beats 98.38 % of cpp submissions
// Your memory usage beats 35.12 % of cpp submissions (58 MB)
// @lc code=end
