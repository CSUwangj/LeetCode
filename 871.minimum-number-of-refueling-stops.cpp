/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if(startFuel >= target) return 0;
    int curFuel = startFuel;
    int len = stations.size();
    if(!len) return -1;
    bool vis[len];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < len; ++i) {
      int maxFuel = curFuel;
      int idx = -1;
      for(int j = 0; j < len; ++j) {
        if(vis[j]) continue;
        if(curFuel < stations[j][0]) break;
        if(curFuel + stations[j][1] > maxFuel) {
          idx = j;
          maxFuel = curFuel + stations[j][1];
        }
      }
      if(idx == -1) return -1;
      if(maxFuel >= target) return i + 1;
      curFuel = maxFuel;
      vis[idx] = true;
    }
    return -1;
  }
};
// @lc code=end

