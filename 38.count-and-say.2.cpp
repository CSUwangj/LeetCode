/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
  string solve(int n) {
    if(n == 1) return "1";
    string prev = solve(n - 1);
    string result = "";
    char current = prev.front();
    int count = 0;
    for(auto c : prev) {
      if(current == c) {
        count += 1;
      } else {
        result += to_string(count) + current;
        current = c;
        count = 1;
      }
    }
    result += to_string(count) + current;
    return result;
  }
public:
  string countAndSay(int n) {
    return solve(n);
  }
};

// Accepted
// 30/30 cases passed (21 ms)
// Your runtime beats 37.31 % of cpp submissions
// Your memory usage beats 42.61 % of cpp submissions (6.7 MB)
// @lc code=end

