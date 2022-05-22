/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void traversal(TreeNode *root, int &rest, int &result) {
    if(!root) return;
    traversal(root->left, rest, result);
    if(result != -1) return;
    if((--rest) == 0) {
      result = root->val;
      return;
    }
    traversal(root->right, rest, result);
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    int answer = -1;
    traversal(root, k, answer);
    return answer;
  }
};

// Accepted
// 93/93 cases passed (7 ms)
// Your runtime beats 99.88 % of cpp submissions
// Your memory usage beats 60.91 % of cpp submissions (24.2 MB)
// @lc code=end
