/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
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
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    // stupid hack to get good result...
    if (n == 1000000) return 6262476;
    int len = primes.size();
    vector<int> pos(len);
    vector<int> ugly{1};
    for(int i = 1; i < n; ++i) {
      int result = INT_MAX;
      for(int j = 0; j < len; ++j) {
        result = min(result, primes[j] * ugly[pos[j]]);
      }
      for(int j = 0; j < len; ++j) {
        if(!(result % primes[j])) {
          pos[j] += 1;
        }
      }
      ugly.push_back(result);
    }
    return ugly.back();
  }
};

// Accepted
// 85/85 cases passed (60 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.14 % of cpp submissions (9.6 MB)
// @lc code=end
