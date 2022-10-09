/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
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
  int minCost(string colors, vector<int>& neededTime) {
    char current = -1;
    int curSum = 0;
    int curMax = 0;
    int answer = 0;
    for(int i = 0; i < colors.length(); ++i) {
      if(colors[i] != current) {
        answer += curSum - curMax;
        current = colors[i];
        curSum = neededTime[i];
        curMax = neededTime[i];
      } else {
        curSum += neededTime[i];
        curMax = max(curMax, neededTime[i]);
      }
    }
    answer += curSum - curMax;
    return answer;
  }
};

// Accepted
// 113/113 cases passed (214 ms)
// Your runtime beats 71.93 % of cpp submissions
// Your memory usage beats 18.68 % of cpp submissions (95.8 MB)
// @lc code=end

