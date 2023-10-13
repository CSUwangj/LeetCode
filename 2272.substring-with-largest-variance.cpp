/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int solve(const string &s, int i, int j) {
    int c1 = 0;
    int c2 = 0;
    int result = 0;
    for(auto c : s) {
      if(c == i) {
        c1 += 1;
      } else if (c == j) {
        c2 += 1;
      }
      if(c1 < c2) {
        c1 = 0;
        c2 = 0;
      }
      if(c1 > c2 && c2) {
        result = max(result, c1 - c2);
      }
    }
    return result;
  }
public:
  int largestVariance(string s) {
    vector<int> cnt(26);
    for(auto &c : s) {
      c -= 'a';
      cnt[c] += 1;
    }
    string rs = s;
    reverse(s.begin(), s.end());

    int answer = 0;
    for(int i = 0; i < 26; ++i) {
      for(int j = 0; j < 26; ++j) {
        if(i == j || !cnt[i] || !cnt[j]) continue;
        answer = max(answer, solve(s, i, j));
        answer = max(answer, solve(rs, i, j));
      }
    }

    return answer;
  }
};

// Accepted
// 138/138 cases passed (333 ms)
// Your runtime beats 25.79 % of cpp submissions
// Your memory usage beats 28.93 % of cpp submissions (7 MB)
// @lc code=end

