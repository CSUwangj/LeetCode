/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
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
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int rows = img1.size();
    int cols = img1.front().size();
    vector<unsigned int> bits1, bits2;
    for(int row = 0; row < rows; ++row) {
      int b1 = 0;
      int b2 = 0;
      for(int col = 0; col < cols; ++col) {
        b1 = (b1 << 1) | img1[row][col];
        b2 = (b2 << 1) | img2[row][col];
      }
      bits1.push_back(b1);
      bits2.push_back(b2);
    }

    int answer = 0;
    for(int i = 1 - rows; i < rows; ++i) {
      for(int j = 1 - rows; j < rows; ++j) {
        int overlap = 0;
        for(int k = 0; k < rows; ++k) {
          if(k + i >= 0 && k + i < rows) {
            overlap += __builtin_popcount(j < 0 ? bits1[k] & (bits2[k + i] << -j) : bits1[k] & (bits2[k + i] >> j)); 
          }
        }
        answer = max(answer, overlap);
      }
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (13 ms)
// Your runtime beats 99.31 % of cpp submissions
// Your memory usage beats 58.33 % of cpp submissions (9.6 MB)
// @lc code=end

