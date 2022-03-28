/*
 * @lc app=leetcode id=1663 lang=cpp
 *
 * [1663] Smallest String With A Given Numeric Value
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
  string getSmallestString(int n, int k) {
    int zs = max<int>(ceil((k - n) / 25.0) - 1, 0);
    k -= zs * 26;
    n -= zs;
    return string(n - 1, 'a') + string(1, 'a'+ k - n) + string(zs, 'z');
  }
};

// Accepted
// 93/93 cases passed (24 ms)
// Your runtime beats 98.47 % of cpp submissions
// Your memory usage beats 63.02 % of cpp submissions (26.5 MB)
// @lc code=end
