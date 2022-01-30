/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1 ,0}};
class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int rows = isWater.size();
    int cols = isWater.front().size();
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(isWater[i][j]) q.push({i, j});
      }
    }
    vector<vector<int>> answer(rows, vector<int>(cols));
    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      for(auto m : moves) {
        int newRow = row + m[0];
        int newCol = col + m[1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(answer[newRow][newCol] || isWater[newRow][newCol]) continue;
        answer[newRow][newCol] = answer[row][col] + 1;
        q.push({newRow, newCol});
      }
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (320 ms)
// Your runtime beats 76.49 % of cpp submissions
// Your memory usage beats 80.88 % of cpp submissions (108.2 MB)
// @lc code=end
