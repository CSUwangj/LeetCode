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
  void init(vector<vector<int>>& heightMap, vector<vector<int>> &waterHeight) {
    vector<vector<int>> maxRight(rows, vector<int>(cols));
    vector<vector<int>> maxLeft(rows, vector<int>(cols));
    vector<vector<int>> maxDown(rows, vector<int>(cols));
    vector<vector<int>> maxUp(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        maxLeft[i][j] = heightMap[i][j];
        if(j && maxLeft[i][j - 1] > maxLeft[i][j]) maxLeft[i][j] = maxLeft[i][j - 1];
        maxUp[i][j] = heightMap[i][j];
        if(i && maxUp[i - 1][j] > maxUp[i][j]) maxUp[i][j] = maxUp[i - 1][j];
      }
      for(int j = cols - 1; j >= 0; --j) {
        maxRight[i][j] = heightMap[i][j];
        if(j != cols - 1 && maxRight[i][j + 1] > maxRight[i][j]) maxRight[i][j] = maxRight[i][j + 1];
      }
    }
    for(int i = rows - 1; i >= 0; --i) {
      for(int j = cols - 1; j >= 0; --j) {
        maxDown[i][j] = heightMap[i][j];
        if(i != rows - 1 && maxDown[i + 1][j] > maxDown[i][j]) maxDown[i][j] = maxDown[i + 1][j];
      }
    }

    int answer = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        waterHeight[i][j] = min({maxDown[i][j], maxUp[i][j], maxLeft[i][j], maxRight[i][j]});
      }
    }
  }
  void fixHeight(
    vector<vector<int>>& heightMap,
    vector<vector<bool>> &visited,
    vector<vector<int>> &waterHeight,
    int row,
    int col
  ) {
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(waterHeight[newRow][newCol] < waterHeight[row][col]) return;
    }

    int height = waterHeight[row][col];
    queue<pair<int, int>> q;
    q.push({row, col});
    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(height >= waterHeight[newRow][newCol] || heightMap[newRow][newCol] > heightMap[row][col]) continue;
        waterHeight[newRow][newCol] = height;
        q.push({newRow, newCol});
      }
    }
  }
  void solve(
    vector<vector<int>>& heightMap,
    vector<vector<bool>> &visited,
    vector<vector<int>> &waterHeight
  ) {
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!visited[i][j] && waterHeight[i][j] > heightMap[i][j]) {
          fixHeight(heightMap, visited, waterHeight, i, j);
        }
      }
    }
  }
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    rows = heightMap.size();
    cols = heightMap.front().size();
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    vector<vector<int>> waterHeight(rows, vector<int>(cols));

    init(heightMap, waterHeight);
    solve(heightMap, visited, waterHeight);
    int answer = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(waterHeight[i][j] > heightMap[i][j]) {
          cout << waterHeight[i][j] << ' ';
          answer += waterHeight[i][j] - heightMap[i][j];
        } 
        else cout << "0 ";
      }

      cout << endl;
    }
    return answer;
  }
};
// @lc code=end

