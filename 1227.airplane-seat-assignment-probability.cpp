/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int len = capacity.size();
    for(int i = 0; i < len; ++i) {
      capacity[i] -= rocks[i];
    }
    sort(capacity.begin(), capacity.end());
    for(int i = 0; i < len && additionalRocks; ++i) {
      if(capacity[i]) {
        if(capacity[i] <= additionalRocks) {
          additionalRocks -= capacity[i];
          capacity[i] = 0;
        } else {
          additionalRocks = 0;
        }
      }
    }
    sort(capacity.begin(), capacity.end());
    return upper_bound(capacity.begin(), capacity.end(), 0) - capacity.begin();
  }
};

// Accepted
// 170/170 cases passed (223 ms)
// Your runtime beats 76.70 % of cpp submissions
// Your memory usage beats 79.56 % of cpp submissions (84.8 MB)
// @lc code=end

