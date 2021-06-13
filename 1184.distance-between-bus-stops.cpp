/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution {
public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int sum = 0;
    int d = 0;
    for(auto i : distance) sum += i;
    for(int i = min(start, destination); i < max(start, destination); ++i) {
      d += distance[i];
    }
    return min(d, sum - d);
  }
};
// @lc code=end

