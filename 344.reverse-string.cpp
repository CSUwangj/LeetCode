/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
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
  void reverseString(vector<char>& s) {
    int len = s.size();
    for(int i = 0; i * 2 < len; ++i) {
      swap(s[i], s[len - 1 - i]);
    }
  }
};

// Accepted
// 477/477 cases passed (20 ms)
// Your runtime beats 89.9 % of cpp submissions
// Your memory usage beats 41.72 % of cpp submissions (23.3 MB)
// @lc code=end
