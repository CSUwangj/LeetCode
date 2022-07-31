/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
string unify(string s) {
  char mp[26] = {};
  int cnt = 0;
  for(auto &c : s) {
    if(!mp[c - 'a']) {
      mp[c - 'a'] = 'a' + cnt;
      cnt += 1;
    }
    c = mp[c - 'a'];
  }
  return s;
}
class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> answer;
    pattern = unify(pattern);
    for(auto &word : words) {
      if(unify(word) == pattern) answer.push_back(word);
    }
    return answer;
  }
};

// Accepted
// 47/47 cases passed (10 ms)
// Your runtime beats 28.33 % of cpp submissions
// Your memory usage beats 98.2 % of cpp submissions (7.7 MB)
// @lc code=end

