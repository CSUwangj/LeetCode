/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
  int deepestLeavesSum(TreeNode* root) {
    int answer = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      answer = 0;
      while(sz--) {
        auto cur = q.front();
        q.pop();
        answer += cur->val;
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
      }
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (120 ms)
// Your runtime beats 65.54 % of cpp submissions
// Your memory usage beats 48.29 % of cpp submissions (61.7 MB)
// @lc code=end
