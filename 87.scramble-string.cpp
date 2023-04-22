/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, bool> result;
public:
  bool isScramble(string s1, string s2) {
    if(s1 == s2) return true;
    int len = s1.length();

    if(result.count(s1 + s2)) return result[s1 + s2];
    vector<int> a(26), b(26), c(26);

    for(int i = 1; i < len; ++i) {
      int j = len - i;
      a[s1[i - 1] - 'a'] += 1;
      b[s2[i - 1] - 'a'] += 1;
      c[s2[j] - 'a'] += 1;

      if(a == b && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
        result[s1 + s2] = true;
        return true;
      }

      if(a == c && isScramble(s1.substr(0, i), s2.substr(j)) && isScramble(s1.substr(i), s2.substr(0, j))) {
        result[s1 + s2] = true;
        return true;
      }
    }

    result[s1 + s2] = false;
    return false;
  }
};

// Accepted
// 288/288 cases passed (3 ms)
// Your runtime beats 99.15 % of cpp submissions
// Your memory usage beats 79.89 % of cpp submissions (15.2 MB)
// @lc code=end

