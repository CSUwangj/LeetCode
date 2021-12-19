/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int maxSquare(vector<int> &counts, vector<int> &st) {
    int len = counts.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && counts[i] < counts[st.back()]) {
        int index = st.back();
        st.pop_back();
        // till the next less
        answer = max(answer, min(i - st.back() - 1, counts[index]));
      }
      st.push_back(i);
    }    
    while(st.back() != -1) st.pop_back();
    return answer;
  }
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    vector<int> dp(cols + 1);
    vector<int> st{-1};
    int sideLength = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
      }
      sideLength = max(sideLength, maxSquare(dp, st));
    }
    return sideLength * sideLength;
  }
};

// Accepted
// 75/75 cases passed (20 ms)
// Your runtime beats 94.4 % of cpp submissions
// Your memory usage beats 75.11 % of cpp submissions (11.4 MB)
// @lc code=end
