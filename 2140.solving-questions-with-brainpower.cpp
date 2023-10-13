/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution {
public:
  long long mostPoints(vector<vector<int>>& questions) {
    map<int, long long> decisions{{-1, 0}};
    long long answer = 0;
    long long maxPossible = 0;
    for(int i = 0; i < questions.size(); ++i) {
      auto it = decisions.upper_bound(i);
      --it;
      maxPossible = max(maxPossible, it->second);
      decisions[i + questions[i][1] + 1] = max(decisions[i + questions[i][1] + 1], maxPossible + questions[i][0]);
      answer = max(decisions[i + questions[i][1] + 1], answer);
    }

    return answer;
  }
};

// Accepted
// 54/54 cases passed (667 ms)
// Your runtime beats 5.17 % of cpp submissions
// Your memory usage beats 9.66 % of cpp submissions (136.4 MB)
// @lc code=end

