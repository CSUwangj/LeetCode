/*
 * @lc app=leetcode id=2029 lang=cpp
 *
 * [2029] Stone Game IX
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
  bool stoneGameIX(vector<int>& stones) {
    int count[3] = {};
    for(auto stone : stones) {
      count[stone % 3] += 1;
    }
    return count[0] % 2 == 0 && count[1] && count[2] || count[0] % 2 == 1 && (abs(count[1] - count[2]) > 2);
  }
};

// Accepted
// 106/106 cases passed (262 ms)
// Your runtime beats 47.1 % of cpp submissions
// Your memory usage beats 9.03 % of cpp submissions (128.1 MB)
// @lc code=end
