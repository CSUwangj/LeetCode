/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
class Solution {
  bool isSubsequence(string shorter, string longer) {
    int pos = 0;
    for(int i = 0; i < longer.length(); ++i) {
      if(longer[i] == shorter[pos]) {
        pos += 1;
      }
      if(pos == shorter.length()) break;
    }
    return pos == shorter.length();
  }
public:
  int findLUSlength(vector<string>& strs) {
    unordered_map<string, int> mp;
    for(int i = 0; i < strs.size(); ++i) {
      bool ok = true;
      for(int j = 0; ok && j < strs.size(); ++j) {
        if(i == j || strs[i].length() >= strs[j].length()) continue;
        ok = !isSubsequence(strs[i], strs[j]);
      }
      if(ok) mp[strs[i]] += 1;
    }
    int answer = 0;
    for(auto &[str, cnt] : mp) {
      if(cnt > 1) continue;
      if(str.length() > answer) answer = str.length();
    }
    return answer ? answer : -1;
  }
};
// @lc code=end

