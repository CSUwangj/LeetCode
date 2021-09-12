/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
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
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    for(auto &op : ops) {
      if(op[0] < m) m = op[0];
      if(op[1] < n) n = op[1];
    }
    return m * n;
  }
};

// Accepted
// 69/69 cases passed (12 ms)
// Your runtime beats 54.99 % of cpp submissions
// Your memory usage beats 57.77 % of cpp submissions (11 MB)
// @lc code=end

