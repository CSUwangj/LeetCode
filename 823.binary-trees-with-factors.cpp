/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    vector<int> count(len, 1);
    for(int i = 1; i < len; ++i) {
      for(int j = 0; arr[i] / arr[j] >= arr[j]; ++j) {
        if(arr[i] % arr[j]) continue;
        int pos = lower_bound(arr.begin(), arr.end(), arr[i] / arr[j]) - arr.begin();
        if(arr[i] / arr[j] != arr[pos]) continue;
        count[i] += (2LL - (arr[j] == arr[pos])) * count[j] * count[pos] % MOD;
        count[i] %= MOD;
      }
    }
    
    int answer = accumulate(count.begin(), count.end(), 0, [](int prev, int cur) {
      return (prev + cur) % MOD;
    });
    return answer;
  }
};

// Accepted
// 48/48 cases passed (67 ms)
// Your runtime beats 90.15 % of cpp submissions
// Your memory usage beats 99.08 % of cpp submissions (8.3 MB)
// @lc code=end

