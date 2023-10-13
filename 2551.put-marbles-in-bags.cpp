/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */

// @lc code=start
class Solution {
public:
  long long putMarbles(vector<int>& weights, int k) {
    int len = weights.size();
    vector<int> sum(len - 1);
    sum.reserve(len - 1);
    for(int i = 1; i < len; ++i) {
      sum[i - 1] = weights[i] + weights[i - 1];
    }

    sort(sum.begin(), sum.end());
    long long answer = 0;
    auto it = sum.begin();
    auto rit = sum.rbegin();
    for(;--k; ++it, ++rit) {
      answer += *rit - *it;
    }

    return answer;
  }
};

// Accepted
// 103/103 cases passed (210 ms)
// Your runtime beats 64.61 % of cpp submissions
// Your memory usage beats 88.66 % of cpp submissions (59.9 MB)
// @lc code=end

