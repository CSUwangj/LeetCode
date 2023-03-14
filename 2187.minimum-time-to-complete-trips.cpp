/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */

// @lc code=start
class Solution {
public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long high = 1e15;
    long long low = 1;
    while(low < high) {
      long long mid = (high + low) >> 1;
      long long total = 0;
      for(auto time : time) {
        total += mid / time;
        if(total > INT_MAX) {
          break;
        }
      }
      if(total < totalTrips) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 123/123 cases passed (270 ms)
// Your runtime beats 86.49 % of cpp submissions
// Your memory usage beats 33.4 % of cpp submissions (94.6 MB)
// @lc code=end

