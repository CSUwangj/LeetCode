/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
  int maxLevelSum(TreeNode* root) {
    int answer;
    int sum = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(q.size()) {
      int sz = q.size();
      int currentSum = 0;
      level += 1;
      for(int _ = 0; _ < sz; ++_) {
        auto current = q.front();
        q.pop();
        currentSum += current->val;
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
      }
      if(currentSum > sum) {
        sum = currentSum;
        answer = level;
      }
    }
    return answer;
  }
};

// Accepted
// 40/40 cases passed (184 ms)
// Your runtime beats 95.85 % of cpp submissions
// Your memory usage beats 13.54 % of cpp submissions (107.5 MB)
// @lc code=end

