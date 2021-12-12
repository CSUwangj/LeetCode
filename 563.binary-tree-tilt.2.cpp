/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
 */

auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int answer = 0;
  int solve(TreeNode *root) {
    if(!root) return 0;
    int leftSum = solve(root->left);
    int rightSum = solve(root->right);
    answer += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
  }
public:
  int findTilt(TreeNode* root) {
    solve(root);
    return answer;
  }
};

// Accepted
// 77/77 cases passed (12 ms)
// Your runtime beats 94.11 % of cpp submissions
// Your memory usage beats 11.69 % of cpp submissions (23.8 MB)
// @lc code=end
