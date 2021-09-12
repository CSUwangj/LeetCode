/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
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
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int count = 0;
    int moveX = 0;
    int moveY = 1;
    int dirMoves = 0;
    int curMoves = 0;
    vector<vector<int>> answer;
    int rPos = rStart;
    int cPos = cStart;
    while(answer.size() < rows * cols) {
      if(rPos < rows && rPos >= 0 && cPos < cols && cPos >= 0) {
        answer.push_back({rPos, cPos});
      }
      rPos += moveX;
      cPos += moveY;
      curMoves += 1;
      if(curMoves > dirMoves / 2) {
        int newMoveX = moveY;
        int newMoveY = -moveX;
        moveX = newMoveX;
        moveY = newMoveY;
        curMoves = 0;
        dirMoves += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 73/73 cases passed (21 ms)
// Your runtime beats 17.53 % of cpp submissions
// Your memory usage beats 54.02 % of cpp submissions (12.3 MB)
// @lc code=end

