/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class BSTIterator {
  TreeNode *cur;
  TreeNode *prev;
  TreeNode *pred;
public:
  BSTIterator(TreeNode* root): cur(root), prev(nullptr) {}
  
  int next() {
    int result = -1;
    while(result < 0) {
      if(!cur->left) {
        result = cur->val;
        prev = cur;
        cur = cur->right;
      } else {
        pred = cur->left;
        while(pred->right && pred->right != cur) pred = pred->right;
        if(pred->right) {
          pred->right = nullptr;
          result = cur->val;
          prev = cur;
          cur = cur->right;
        } else {
          pred->right = cur;
          cur = cur->left;
        }
      }
    }
    return result;
  }
  
  bool hasNext() {
    return cur;
  }
};

// Accepted
// 61/61 cases passed (28 ms)
// Your runtime beats 87.25 % of cpp submissions
// Your memory usage beats 99.91 % of cpp submissions (23.9 MB)
// @lc code=end
