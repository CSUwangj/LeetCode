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
    vector<int> p1, p2;
    for(int row = 0; row < rows; ++row) {
      for(int col = 0; col < cols; ++col) {
        if(img1[row][col]) {
          p1.push_back(row * 60 + col);
        }
        if(img2[row][col]) {
          p2.push_back(row * 60 + col);
        }
      }
    }
    unordered_map<int, int> count;
    for(const auto c1 : p1) {
      for(const auto c2 : p2) {
        count[c1 - c2] += 1;
      }
    }
    int answer = 0;
    for(const auto &[_, result] : count) {
      answer = max(answer, result);
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (90 ms)
// Your runtime beats 78.47 % of cpp submissions
// Your memory usage beats 34.03 % of cpp submissions (12.3 MB)
// @lc code=end

