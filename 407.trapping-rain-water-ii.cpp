/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  int answer = 0;
  using pi_heap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
  void dfs(
    vector<vector<bool>> &visited,
    pi_heap &pq,
    vector<vector<int>>& heightMap,
    int row,
    int col,
    int height
  ) {
    // cout << row << ' ' << col << ' ' << height << endl;
    answer += height - heightMap[row][col];
    heightMap[row][col] = height;
    visited[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol >= cols || newCol < 0) continue;
      if(visited[newRow][newCol]) continue;
      if(heightMap[newRow][newCol] < height) {
        dfs(visited, pq, heightMap, newRow, newCol, height);
      } else {
        pq.push({heightMap[newRow][newCol], newRow * cols + newCol});
      }
    }
  }
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    rows = heightMap.size();
    cols = heightMap.front().size();
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    pi_heap pq;
    for(int i = 0; i < rows; ++i) {
      pq.push({heightMap[i][0], i * cols});
      pq.push({heightMap[i][cols - 1], i * cols + cols - 1});
    }
    for(int j = 0; j < cols; ++j) {
      pq.push({heightMap[0][j], j});
      pq.push({heightMap[rows - 1][j], (rows - 1) * cols + j});

    }
    while(pq.size()) {
      auto [height, position] = pq.top();
      pq.pop();
      dfs(visited, pq, heightMap, position / cols, position % cols, height);
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (232 ms)
// Your runtime beats 14.6 % of cpp submissions
// Your memory usage beats 11.8 % of cpp submissions (27.6 MB)
// @lc code=end

