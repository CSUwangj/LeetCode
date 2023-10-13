/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
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
  int diagonalSum(vector<vector<int>>& mat) {
    int len = mat.size();
    int sum = 0;
    for(int i = 0; i < len; ++i) {
      sum += mat[i][i] + mat[i][len - 1 - i];
    }
    if(len & 1) sum -= mat[len/2][len/2];
    return sum;
  }
};

// Accepted
// 113/113 cases passed (16 ms)
// Your runtime beats 52.8 % of cpp submissions
// Your memory usage beats 17.56 % of cpp submissions (11.4 MB)
// @lc code=end

