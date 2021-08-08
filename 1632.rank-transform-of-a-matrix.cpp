/*
 * @lc app=leetcode id=1632 lang=cpp
 *
 * [1632] Rank Transform of a Matrix
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
using pi = pair<int, int>;
class Solution {
  int rows;
  int cols;
  vector<int> parents;
  vector<int> maxRankInRow;
  vector<int> maxRankInCol;
  int find(int x) {
    if(parents[x] != x) parents[x] = find(parents[x]);
    return parents[x];
  }
  void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parents[px] = parents[py];
  }

  void init(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix.front().size();
    maxRankInRow.resize(rows, INT_MIN);
    maxRankInCol.resize(cols, INT_MIN);
    parents.resize(rows + cols);
    vector<pi> vals;
    sort(vals.begin(), vals.end(), greater<pi>());
  }

  void solveVal(
    vector<vector<int>> &answer,
    vector<pi> &positions
  ) {
    for(int i = 0; i < rows + cols; ++i) {
      parents[i] = i;
    }
    for(auto [row, col] : positions) {
      merge(row, col + cols);
    }
    unordered_map<int, vector<pi>> groups;
    for(auto [row, col] : positions) {
      groups[find(row)].push_back({row, col});
    }

    for(auto &[_, group] : groups) {
      int rank = 1;
      for(auto [row, col] : group) {
        rank = max(rank, max(maxRankInRow[row], maxRankInCol[col]) + 1);
      }
      for(auto [row, col] : group) {
        answer[row][col] = rank;
        maxRankInCol[col] = max(rank, maxRankInCol[col]);
        maxRankInRow[row] = max(rank, maxRankInRow[row]);
      }
    }
  }
public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    init(matrix);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        pq.push({matrix[i][j], i * cols + j});
      }
    }

    vector<vector<int>> answer(rows, vector<int>(cols));
    vector<pi> sameVal;
    int prev = INT_MIN;
    while(pq.size()) {
      auto [val, pos] = pq.top();
      pq.pop();
      int row = pos / cols;
      int col = pos % cols;
      if(prev != val) {
        solveVal(answer, sameVal);
        sameVal.clear();
        prev = val;
      }
      sameVal.push_back({row, col});
    }
    solveVal(answer, sameVal);
    return answer;
  }
};

// Accepted
// 39/39 cases passed (344 ms)
// Your runtime beats 52.98 % of cpp submissions
// Your memory usage beats 82.09 % of cpp submissions (75.4 MB)
// @lc code=end

