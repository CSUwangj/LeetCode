/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */

// @lc code=start
class Solution {
public:
  int partitionString(string s) {
    vector<int> count(26);
    int answer = 1;
    for(auto c : s) {
      if(count[c - 'a']) {
        fill(count.begin(), count.end(), 0);
        answer += 1;
      }
      count[c - 'a'] += 1;
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (28 ms)
// Your runtime beats 83.48 % of cpp submissions
// Your memory usage beats 90.34 % of cpp submissions (10.3 MB)
// @lc code=end

