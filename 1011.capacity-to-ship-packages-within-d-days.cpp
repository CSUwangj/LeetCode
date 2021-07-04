/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
  bool validate(vector<int> &weights, int days, int capacity) {
    int cur = 0;
    int ships = 1;
    for(auto w : weights) {
      if(cur + w > capacity) {
        cur = w;
        ships += 1;
      } else {
        cur += w;
      }
      if(ships > days) return false;
    }
    // cout << capacity << ' ' << days << endl;
    return true;
  }
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int maxW = *max_element(weights.begin(), weights.end());
    int len = weights.size();
    if(days >= len) return maxW;
    if(days == 1) return sum;
    int low = maxW;
    int high = sum;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(validate(weights, days, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
// @lc code=end

