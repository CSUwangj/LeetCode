/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon.front().size();
    if(dungeon.back().back() > 0) dungeon.back().back() = 0;
    for(int row = rows - 1; row >= 0; row -= 1) {
      for(int col = cols - 1; col >= 0; col -= 1) {
        if(col == cols - 1 && row == rows - 1) continue;
        int maxDown = row == rows - 1 ? INT_MIN : dungeon[row + 1][col];
        int maxRight = col == cols - 1 ? INT_MIN : dungeon[row][col + 1];
        int target = max(maxDown, maxRight) + dungeon[row][col];
        dungeon[row][col] = target < 0 ? target : 0;
      }
    }
    return dungeon.front().front() < 1 ? 1 - dungeon.front().front() : 1;
  }
};

// Accepted
// 45/45 cases passed (4 ms)
// Your runtime beats 95.38 % of cpp submissions
// Your memory usage beats 83.37 % of cpp submissions (8.7 MB)
// @lc code=end

