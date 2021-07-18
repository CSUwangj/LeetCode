/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
public:
  string customSortString(string order, string str) {
    int cnt[128] = {};
    for(auto c : str) cnt[c] += 1;
    string answer;
    for(auto c : order) {
      while(cnt[c]) {
        answer.push_back(c);
        cnt[c] -= 1;
      }
    }
    for(char i = 'a'; i <= 'z'; ++i) {
      while(cnt[i]) {
        answer.push_back(i);
        cnt[i] -= 1;
      }
    }
    return answer;
  }
};
// @lc code=end

