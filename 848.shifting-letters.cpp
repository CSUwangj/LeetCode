/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
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
  string shiftingLetters(string s, vector<int>& shifts) {
    int shift = 0;
    for(int i = s.length() - 1; i >= 0; --i) {
      shift += shifts[i];
      shift %= 26;
      s[i] = (s[i] - 'a' + shift) % 26 + 'a';
    }
    return s;
  }
};

// Accepted
// 53/53 cases passed (124 ms)
// Your runtime beats 62.03 % of cpp submissions
// Your memory usage beats 20.29 % of cpp submissions (68.1 MB)
// @lc code=end

