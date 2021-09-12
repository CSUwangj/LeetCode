/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[100][100];
class Solution {
public:
  int strangePrinter(string target) {
    string s;
    s.push_back(target.front());
    for(auto c : target) {
      if(c != s.back()) {
        s.push_back(c);
      }
    }
    int len = s.length();
    for(int l = 0; l < len; ++l) {
      for(int left = 0; left + l < len; ++left) {
        int right = left + l;
        if(!l) {
          dp[left][right] = 1;
        } else {
          dp[left][right] = dp[left][right - 1] + 1;
        }
        for(int middle = left; middle < right; middle += 1) {
          if(s[middle] == s[right]) {
            dp[left][right] = min(dp[left][right], dp[left][middle] + dp[middle + 1][right - 1]);
          }
        }
      }
    }
    return dp[0][len - 1];
  }
};

// Accepted
// 200/200 cases passed (12 ms)
// Your runtime beats 98.86 % of cpp submissions
// Your memory usage beats 66.76 % of cpp submissions (6.3 MB)
// @lc code=end

