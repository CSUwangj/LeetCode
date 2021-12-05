/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
  int largestRectangleArea(vector<int>& heights, vector<int> &st) {
    heights.push_back(0);
    int len = heights.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && heights[i] < heights[st.back()]) {
        int index = st.back();
        st.pop_back();
        int h = heights[index];
        int w = i - st.back() - 1;
        answer = max(answer, h*w);
      }
      st.push_back(i);
    }
    while(st.size() != 1) st.pop_back();
    return answer;
  }
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int> st{-1};
    int row = matrix.size();
    if(!row) return 0;
    int col = matrix.front().size();
    vector<int> dp(col);
    int answer = 0;
    for(int i = 0; i < row; ++i) {
      for(int j = 0; j < col; ++j) {
        if(matrix[i][j] == '1') {
          dp[j] = dp[j] + 1;
        } else {
          dp[j] = 0;
        }
      }
      answer = max(answer, largestRectangleArea(dp, st));
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (24 ms)
// Your runtime beats 95.14 % of cpp submissions
// Your memory usage beats 90.31 % of cpp submissions (11 MB)
// @lc code=end
