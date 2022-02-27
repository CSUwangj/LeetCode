/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
  int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    long long answer = 0;
    queue<pair<long long, TreeNode*>> q;
    q.push({0, root});
    while(q.size()) {
      int sz = q.size();
      long long mmin = INT_MAX;
      long long mmax = INT_MIN;
      for(int _ = 0; _ < sz; ++_) {
        auto [index, cur] = q.front();
        mmin = min(index, mmin);
        mmax = max(index, mmax);
        q.pop();
        if(cur->left) q.push({index * 2 - mmin, cur->left});
        if(cur->right) q.push({index * 2 + 1 - mmin, cur->right});
      }
      answer = max(answer, mmax - mmin + 1);
    }
    return answer;
  }
};

// Accepted
// 113/113 cases passed (18 ms)
// Your runtime beats 28.12 % of cpp submissions
// Your memory usage beats 21.15 % of cpp submissions (17.4 MB)
// @lc code=end
