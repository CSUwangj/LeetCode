/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
constexpr int MAX = 200 * 200;
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  int parent[MAX];
  int size[MAX];
  int height[MAX] = {};
  bool edge[MAX] = {};
  bool visit[MAX] = {};

  void init() { 
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        int idx = i * cols + j;
        parent[idx] = idx;
        size[idx] = 1;
        if(!j || !i || i == rows - 1 || j == cols - 1) edge[idx] = true;
      }
    }
  }

  int find(int x) {
    if(parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    size[px] += size[py];
    height[px] = max(height[px], height[py]);
    edge[px] |= edge[py];
    parent[y] = px;
  }
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    rows = heightMap.size();
    cols = heightMap.front().size();
    int total = rows * cols;
    init();
    
    pair<int, int> heights[total];
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        heights[i * cols + j] = {heightMap[i][j], i * cols + j};
      }
    }
    sort(heights, heights + total);
    
    int answer = 0;
    for(int i = 0; i < total; ++i) {
      int h = heights[i].first;
      int idx = heights[i].second;
      int row = idx / cols;
      int col = idx % cols;
      visit[idx] = true;
      height[idx] = h;
      for(int j = 0; j < 4; ++j) {
        // cout << i << ' ' << j << ' ' << answer << endl; 
        int newRow = row + moves[j][0];
        int newCol = col + moves[j][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        int newIdx = newRow * cols + newCol;
        newIdx = find(newIdx);
        if(!visit[newIdx]) continue;
        if(!edge[newIdx]) {
          answer += (h - height[newIdx]) * size[newIdx];
        }
        merge(idx, newIdx);
      }
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (52 ms)
// Your runtime beats 97.25 % of cpp submissions
// Your memory usage beats 94.37 % of cpp submissions (13 MB)
// @lc code=end

