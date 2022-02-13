/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool checkInclusion(string p, string s) {
    int sLen = s.length();
    int pLen = p.length();
    if(sLen < pLen) return false;
    vector<int> target(26);
    for(auto c : p) {
      target[c - 'a'] += 1;
    }
    vector<int> current(26);
    for(int i = 0; i < pLen; ++i) {
      current[s[i] - 'a'] += 1;
    }
    vector<int> answer;
    for(int i = pLen; i < sLen; ++i) {
      if(current == target) return true;
      current[s[i] - 'a'] += 1;
      current[s[i - pLen] - 'a'] -= 1;
    }
    if(current == target) return true;
    return false;
  }
};

// Accepted
// 106/106 cases passed (8 ms)
// Your runtime beats 77.01 % of cpp submissions
// Your memory usage beats 89.63 % of cpp submissions (7.2 MB)
// @lc code=end
