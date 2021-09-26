/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
  int moves[4];
  vector<bool> visit;
  int cols;
  int total;
  
  void init() {
    moves[0] = 1;
    moves[1] = cols;
    moves[2] = -1;
    moves[3] = -cols;
  }
  
  bool check(int pos, int direction) {
    return (direction == 0 && !((pos+1) % cols)) || \
            (pos + moves[direction] >= total)    || \
            (direction == 2 && !(pos % cols))    || \
            (pos + moves[direction] < 0)         || \
            visit[pos+moves[direction]]; 
  }
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    cols = matrix.front().size();
    total = cols * matrix.size();
    init();
    visit.resize(total);
    vector<int> answer;
    int direction = 0, pos = 0;
    while(answer.size() < total) {
      answer.push_back(matrix[pos/cols][pos%cols]);
      visit[pos] = true;
      int turns = 0;
      while(turns < 4 && check(pos, direction)) {
          turns += 1;
          direction = (direction + 1) % 4;
      }
      pos += moves[direction];
    }
    return move(answer);
  }
};

// Accepted
// 23/23 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.32 % of cpp submissions (6.8 MB)
// @lc code=end

