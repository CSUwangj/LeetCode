/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
unordered_map<string, int> cache;
class Solution {
  bool isPalindrome(string &s, int len) {
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int minCut(string s) {
    if(cache.count(s)) return cache[s];
    int len = s.length();
    if(isPalindrome(s, len)) return 0;
    int answer = len - 1;
    for(int i = 1; i < len; ++i) {
      if(isPalindrome(s, i)) {
        answer = min(answer, 1 + minCut(s.substr(i)));
      }
    }
    // cout << s << ' ' << answer << endl;
    return cache[s] = answer;
  }
};
// Accepted
// 33/33 cases passed (792 ms)
// Your runtime beats 5.05 % of cpp submissions
// Your memory usage beats 8.67 % of cpp submissions (217.4 MB)
// @lc code=end

