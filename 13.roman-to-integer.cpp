/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
unordered_map<char, int> mp = {
  {'M', 1000},
  {'D', 500},
  {'C', 100},
  {'L', 50},
  {'X', 10},
  {'V', 5},
  {'I', 1}
};
class Solution {
public:
  int romanToInt(string s) {
    int len = s.length();
    int pos = 0;
    int answer = 0;
    while(pos < len) {
      if(pos < len - 1 && mp[s[pos]] < mp[s[pos + 1]]) {
        answer += mp[s[pos + 1]] - mp[s[pos]];
        pos += 2;
      } else {
        answer += mp[s[pos]];
        pos += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 3999/3999 cases passed (12 ms)
// Your runtime beats 71.04 % of cpp submissions
// Your memory usage beats 86.74 % of cpp submissions (6 MB)
// @lc code=end

