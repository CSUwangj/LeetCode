/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> answer;
    for(int mask = (1 << k) - 1; mask < (1 << n); mask = (mask + (mask & -mask)) | ((mask & ~(mask + (mask & -mask))) / (mask & -mask) >> 1)) {
      vector<int> result;
      for(int i = 0; i < n; ++i) {
        if(mask & (1 << i)) {
          result.push_back(i + 1);
        }
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 27/27 cases passed (11 ms)
// Your runtime beats 95.34 % of cpp submissions
// Your memory usage beats 40.55 % of cpp submissions (10.6 MB)
// @lc code=end
