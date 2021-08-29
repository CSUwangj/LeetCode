/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
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
    sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
      return s1.length() < s2.length();
    });
    unordered_map<string, int> count;
    for(auto &s : strs) {
      count[s] += 1;
    }
    int answer = -1;
    int len = strs.size();
    for(int i = 0; i < len; ++i) {
      if(count[strs[i]] > 1) continue;
      bool ok = true;
      for(int j = i + 1; ok && j < len; ++j) {
        if(isSubsequence(strs[i], strs[j])) ok = false;
      }
      if(ok) answer = strs[i].length();
    }
    return answer;
  }
};

// Accepted
// 98/98 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 15.49 % of cpp submissions (8.6 MB)
// @lc code=end

