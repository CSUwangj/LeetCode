/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
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
  int minFallingPathSum(vector<vector<int>>& arr) {
    pair<int, int> smallest{0, -1}, secondSmallest{0, -1};
    pair<int, int> tmp1{INT_MAX, -1}, tmp2{INT_MAX, -1};
    int n = arr.size();
    for(auto &row : arr) {
      for(int i = 0; i < n; ++i) {
        int result;
        if(i == smallest.second) {
          result = row[i] + secondSmallest.first;
        } else {
          result = row[i] + smallest.first;
        }
        if(result < tmp1.first) {
          tmp2 = tmp1;
          tmp1 = {result, i};
        } else if (result < tmp2.first) {
          tmp2 = {result, i};
        }
      }
      swap(tmp1, smallest);
      swap(tmp2, secondSmallest);
      tmp1 = {INT_MAX, -1};
      tmp2 = {INT_MAX, -1};
    }
    return smallest.first;
  }
};

// Accepted
// 13/13 cases passed (12 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 68.84 % of cpp submissions (13.1 MB)
// @lc code=end

