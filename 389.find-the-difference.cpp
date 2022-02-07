/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
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
  char findTheDifference(string s, string t) {
    int count[26] = {};
    for(auto c : s) {
      count[c - 'a'] += 1;
    }
    for(auto c : t) {
      count[c - 'a'] -= 1;
    }
    for(int i = 0; i < 26; ++i) {
      if(count[i]) return i + 'a';
    }
    return 0;
  }
};

// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.58 % of cpp submissions (6.6 MB)
// @lc code=end
