/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
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
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> AA(6), BB(6), same(6);
    int len = A.size();
    for(int i = 0; i < len; ++i) {
      AA[A[i] - 1] += 1;
      BB[B[i] - 1] += 1;
      if(A[i] == B[i]) same[A[i] - 1] += 1;
    }
    for(int i = 0; i < 6; ++i) {
      if(AA[i] + BB[i] - same[i] >= len) {
        return len - max(AA[i], BB[i]);
      }
    }
    return -1;
  }
};

// Accepted
// 83/83 cases passed (84 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 10.64 % of cpp submissions (111.7 MB)
// @lc code=end
