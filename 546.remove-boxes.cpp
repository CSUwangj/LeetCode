/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[101][101][101];
class Solution {
  int solve(vector<int> &boxes, int begin, int end, int cnt) {
    if(begin >= end) return 0;
    if(dp[begin][end][cnt]) return dp[begin][end][cnt];
    int result = (cnt + 1) * (cnt + 1) + solve(boxes, begin + 1, end, 0);
    for(int i = begin + 1; i < end; ++i) {
      if(boxes[i] == boxes[begin]) result = max(result, solve(boxes, begin + 1, i, 0) + solve(boxes, i, end, cnt + 1));
    }
    dp[begin][end][cnt] = result;
    return dp[begin][end][cnt];
  }
public:
  int removeBoxes(vector<int>& boxes) {
    int len = boxes.size();
    memset(dp, 0, sizeof(dp[0]) * len);
    return solve(boxes, 0, len, 0);
  }
};

// Accepted
// 62/62 cases passed (254 ms)
// Your runtime beats 36.25 % of cpp submissions
// Your memory usage beats 93.28 % of cpp submissions (11.6 MB)
// @lc code=end

