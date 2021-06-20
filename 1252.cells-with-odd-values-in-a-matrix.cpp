/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    bool bm[50] = {};
    bool bn[50] = {};
    for(auto &index : indices) {
      bm[index[0]] = !bm[index[0]];
      bn[index[1]] = !bn[index[1]];
    }
    int oddRows = 0;
    for(int i = 0; i < m; i++) oddRows += bm[i];
    int evenRows = m - oddRows;

    int answer = 0;
    for(int i = 0; i < n; i++) {
      if(bn[i]) answer += evenRows;
      else answer += oddRows;
    }
    return answer;
  }
};
// @lc code=end

