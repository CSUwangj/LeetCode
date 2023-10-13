/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> right(n + 1);
    for(int i = 0; i <= n; ++i) {
      if(!ranges[i]) continue;
      int left = max(i - ranges[i], 0);
      if(right[left] < i + ranges[i]) {
        right[left] = i + ranges[i];
      }
    }
    int count = 0;
    int rightMost = 0;
    int end = 0;
    for(int i = 0; i <= n; ++i) {
      if(end < i) {
        if(rightMost <= end) return -1;
        end = rightMost;
        count += 1;
      }
      rightMost = max(rightMost, right[i]);
    }

    return count + (end < n);
  }
};

// Accepted
// 38/38 cases passed (14 ms)
// Your runtime beats 85.18 % of cpp submissions
// Your memory usage beats 55.15 % of cpp submissions (14.6 MB)
// @lc code=end

