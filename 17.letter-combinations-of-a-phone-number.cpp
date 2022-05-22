/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
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
  vector<string> letterCombinations(string digits) {
    if(digits.empty()) return vector<string>();
    vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> nxt;
    vector<string> current{""};
    for(auto c : digits) {
      for(auto &s : current) {
        for(auto letter : mp[c-'2']) {
          nxt.push_back(s+letter);
        }
      }
      current = nxt;
      nxt.clear();
    }
    return current;
  }
};

// Accepted
// 25/25 cases passed (4 ms)
// Your runtime beats 26.23 % of cpp submissions
// Your memory usage beats 35.85 % of cpp submissions (6.6 MB)
// @lc code=end