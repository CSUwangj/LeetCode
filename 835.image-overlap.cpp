/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int rows = img1.size();
    int cols = img1.front().size();
    vector<pair<int, int>> p1, p2;
    for(int row = 0; row < rows; ++row) {
      for(int col = 0; col < cols; ++col) {
        if(img1[row][col]) {
          p1.push_back({row, col});
        }
        if(img2[row][col]) {
          p2.push_back({row, col});
        }
      }
    }
    unordered_map<string, int> count;
    for(const auto &[r1, c1] : p1) {
      for(const auto &[r2, c2] : p2) {
        count[to_string(r1 - r2) + ":" + to_string(c1 - c2)] += 1;
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
// 59/59 cases passed (1473 ms)
// Your runtime beats 5.56 % of cpp submissions
// Your memory usage beats 8.33 % of cpp submissions (14.5 MB)
// @lc code=end

