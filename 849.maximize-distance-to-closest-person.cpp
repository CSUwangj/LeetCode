/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start
class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    bool begin = true;
    int count = 0;
    int answer = 0;
    for(auto seat : seats) {
      if(!seat) {
        count += 1;
        continue;
      }
      if(begin) {
        count *= 2;
        begin = false;
      }
      answer = max(answer, count / 2);
      count = 1;
    }
    if(count > 1) answer = max(answer, count - 1);
    return answer;
  }
};

// Accepted
// 81/81 cases passed (8 ms)
// Your runtime beats 96.68 % of cpp submissions
// Your memory usage beats 63.67 % of cpp submissions (17 MB)
// @lc code=end
