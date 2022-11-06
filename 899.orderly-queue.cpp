/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
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
  string orderlyQueue(string s, int k) {
    if(k > 1) {
      sort(s.begin(), s.end());
      return s;
    }
    string answer = s;
    int len = s.length();
    for(int i = 1; i < len; ++i) {
      answer = min(answer, s.substr(i) + s.substr(0, i));
    }
    return answer;
  }
};

// Accepted
// 111/111 cases passed (16 ms)
// Your runtime beats 13.22 % of cpp submissions
// Your memory usage beats 32.18 % of cpp submissions (10.8 MB)
// @lc code=end