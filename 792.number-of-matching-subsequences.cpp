/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
  bool isSubsequence(const vector<vector<int>> &pos, string &word) {
    int prev = -1;
    for(auto c : word) {
      int cha = c - 'a';
      int idx = upper_bound(pos[cha].begin(), pos[cha].end(), prev) - pos[cha].begin();
      if(idx == pos[cha].size()) return false;
      prev = pos[cha][idx];
    }
    return true;
  }
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> pos(26);
    for(int i = 0; i < s.length(); ++i) {
      pos[s[i] - 'a'].push_back(i);
    }
    int answer = 0;
    for(auto &word : words) {
      answer += isSubsequence(pos, word);
    }
    return answer;
  }
};

// Accepted
// 52/52 cases passed (225 ms)
// Your runtime beats 83.68 % of cpp submissions
// Your memory usage beats 70.32 % of cpp submissions (48.1 MB)
// @lc code=end

