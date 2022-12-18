/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
    int len = arr.size();
    if(len == 1) return arr[0];
    vector<int> left(len), right(len);
    vector<pair<int, int>> monoStack;
    vector<pair<int, int>> momoStack;
    for(int i = 0; i < len; ++i) {
      left[i] = i + 1;
      right[i] = len - i;
    }
    for(int i = 0; i < len; ++i) {
      while(monoStack.size() && monoStack.back().first >= arr[i]) {
        monoStack.pop_back();
      }
      left[i] = monoStack.size() ? i - monoStack.back().second : i + 1;
      monoStack.push_back({arr[i], i});

      while(momoStack.size() && momoStack.back().first >= arr[i]) {
        auto pos = momoStack.back().second;
        momoStack.pop_back();
        right[pos] = i - pos;
      }
      momoStack.push_back({arr[i], i});
    }
    long long answer = 0;
    constexpr int MOD = 1e9 + 7;
    for(int i = 0; i < len; ++i) {
      answer += 1LL * right[i] * left[i] * arr[i];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 87/87 cases passed (100 ms)
// Your runtime beats 95.32 % of cpp submissions
// Your memory usage beats 13.34 % of cpp submissions (44.2 MB)
// @lc code=end
