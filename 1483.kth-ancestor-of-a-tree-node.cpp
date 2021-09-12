/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class TreeAncestor {
  vector<vector<int>> dp;
public:
  TreeAncestor(int n, vector<int>& parent) {
    dp.resize(20, vector<int>(n + 1, -1));

    for(int i = 0; i < n; ++i) {
      dp[0][i] = parent[i];
    }

    for(int i = 1; i < 20; ++i) {
      for(int j = 1; j < n; ++j) {
        int xParent = dp[i - 1][j];
        if(xParent == -1) {
          dp[i][j] = -1;
        } else {
          dp[i][j] = dp[i - 1][xParent];
        }
      }
    }
  }
  
  int getKthAncestor(int node, int k) {
    for(int i = 0; i < 20 && node != -1; ++i) {
      if(k & (1 << i)) {
        node = dp[i][node];
      }
    }

    return node;
  }
};

// Accepted
// 16/16 cases passed (240 ms)
// Your runtime beats 98.19 % of cpp submissions
// Your memory usage beats 89.46 % of cpp submissions (110.7 MB)
// @lc code=end

