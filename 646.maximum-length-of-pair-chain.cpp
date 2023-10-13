/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
      return a[1] < b[1];
    });
    int cur = INT_MIN;
    int answer = 0;
    for(auto &p : pairs) {
      if(p[0] > cur) {
        cur = p[1];
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 206/206 cases passed (43 ms)
// Your runtime beats 98.67 % of cpp submissions
// Your memory usage beats 86.44 % of cpp submissions (22.5 MB)
// @lc code=end

