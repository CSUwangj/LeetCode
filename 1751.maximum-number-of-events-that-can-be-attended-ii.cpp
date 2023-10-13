/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
class Solution {
public:
  int maxValue(vector<vector<int>>& events, int k) {
    int len = events.size();
    vector<int> index(len);
    for(int i = 0; i < len; ++i) index[i] = i;
    sort(index.begin(), index.end(), [&](int a, int b) {
      return events[a][1] < events[b][1];
    });
    vector<int> dp(len);
    vector<int> compatible(len, -1);
    for(int i = 0; i < len; ++i) {
      for(int j = i - 1; j >= 0; --j) {
        if(events[index[j]][1] < events[index[i]][0]) {
          compatible[i] = j;
          break;
        }
      }
    }

    int answer = 0;
    for(int i = 0; i < len; ++i) dp[i] = events[index[i]][2];
    for(int i = 1; i < k; ++i) {
      for(int j = len-1; j >= 0; --j) {
        if(compatible[j] != -1) {
          for(int pos = compatible[j]; pos >= 0; --pos) {
            dp[j] = max(dp[j], dp[pos] + events[index[j]][2]);
          }
          
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

// Accepted
// 67/67 cases passed (314 ms)
// Your runtime beats 82.15 % of cpp submissions
// Your memory usage beats 98.26 % of cpp submissions (51.6 MB)
// @lc code=end

