/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
  const int MOVES[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
  const double EPS = 1e-10;
public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<double>> probability(n, vector<double>(n));
    probability[row][column] = 1;
    queue<pair<int, int>> q;
    q.push({row, column});

    while(k--) {
      vector<vector<double>> next(n, vector<double>(n));
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int m = 0; m < 8; ++m) {
          int newRow = row + MOVES[m][0];
          int newCol = col + MOVES[m][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(next[newRow][newCol] < EPS) {
            q.push({newRow, newCol});
          }
          next[newRow][newCol] += probability[row][col] / 8;
        }
      }
      probability = next;
    }
    double answer = 0;
    for(int i = 0; i < n; ++i) {
      answer += accumulate(probability[i].begin(), probability[i].end(), 0.0);
    }

    return answer;
  }
};

// Accepted
// 22/22 cases passed (26 ms)
// Your runtime beats 43.39 % of cpp submissions
// Your memory usage beats 23.55 % of cpp submissions (10 MB)
// @lc code=end

