/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int rows = heightMap.size();
    int cols = heightMap.front().size();
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
        int h = min({maxDown[i][j], maxUp[i][j], maxLeft[i][j], maxRight[i][j]});
        answer += h > heightMap[i][j] ? h - heightMap[i][j] : 0;
      }
    }

    return answer;
  }
};
// @lc code=end

