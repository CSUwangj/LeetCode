/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int a = 0;
    int answer = 0;
    for(auto i : gain) {
      a += i;
      answer = max(a, answer);
    }
    return answer;
  }
};

// Accepted
// 80/80 cases passed (6 ms)
// Your runtime beats 28.46 % of cpp submissions
// Your memory usage beats 93.43 % of cpp submissions (7.9 MB)
// @lc code=end

