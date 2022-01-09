/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
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
  bool isRobotBounded(string instructions) {
    const int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int x = 0;
    int y = 0;
    int direction = 0;
    for(int _ = 0; _ < 4; ++_) {
      for(auto instruction : instructions) {
        switch(instruction) {
          case 'G':
            x += moves[direction][1];
            y += moves[direction][0];
            break;
          case 'R':
            direction = (direction + 1) % 4;
            break;
          case 'L':
            direction = (direction + 3) % 4;
            break;
        }
      }
    } 
    return !x && !y;
  }
};

// Accepted
// 116/116 cases passed (2 ms)
// Your runtime beats 18.24 % of cpp submissions
// Your memory usage beats 48.4 % of cpp submissions (6.1 MB)
// @lc code=end
