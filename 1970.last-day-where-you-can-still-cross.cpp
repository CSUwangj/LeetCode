/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    for(int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
};
const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int latestDayToCross(int rows, int cols, vector<vector<int>>& cells) {
    UnionSet us(rows * cols + 2);
    vector<vector<bool>> land(rows, vector<bool>(cols, false));
    int top = 0;
    int bottom = rows * cols + 1;
    for(int i = cells.size() - 1; i >= 0; --i) {
      if(us.find(top) == us.find(bottom)) return i + 1;
      int row = cells[i][0] - 1;
      int col = cells[i][1] - 1;
      int position = row * cols + col + 1;
      if(row == 0) us.merge(top, position);
      if(row == rows - 1) us.merge(bottom, position);
      land[row][col] = true;
      for(int m = 0; m < 4; ++m) {
        int newRow = row + MOVES[m][0];
        int newCol = col + MOVES[m][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(!land[newRow][newCol]) continue;
        us.merge(position, newRow * cols + newCol + 1);
      }
    }
    return 0;
  }
};

// Accepted
// 118/118 cases passed (366 ms)
// Your runtime beats 81.08 % of cpp submissions
// Your memory usage beats 85.13 % of cpp submissions (106.1 MB)
// @lc code=end

