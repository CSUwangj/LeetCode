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
    vector<int> answer;
    pattern = unify(pattern);
    for(auto &word : words) {
      if(unify(word) == pattern) answer.push_back(word);
    }
    return answer;
  }
};
// @lc code=end

