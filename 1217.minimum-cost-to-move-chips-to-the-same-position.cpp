/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
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
  int minCostToMoveChips(vector<int>& position) {
    int parity[2] = {0};
    for(auto p : position) {
      parity[p&1] += 1;
    }
    return parity[0] < parity[1] ? parity[0] : parity[1];
  }
};

// Accepted
// 51/51 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 53.85 % of cpp submissions (7.3 MB)
// @lc code=end
