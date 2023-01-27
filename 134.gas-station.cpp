/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
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
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    for(int i = 0; i < len; ++i) {
      gas[i] -= cost[i];
    }
    int begin = 0;
    while(begin < len) {
      int current = 0;
      for(int i = 0; i < len; ++i) {
        current += gas[(begin + i) % len];
        if(current < 0) {
          begin = begin + i + 1;
          break;
        }
      }
      if(current >= 0) return begin;
    }
    return -1;
  }
};

// Accepted
// 37/37 cases passed (75 ms)
// Your runtime beats 98.16 % of cpp submissions
// Your memory usage beats 12.9 % of cpp submissions (69.6 MB)
// @lc code=end