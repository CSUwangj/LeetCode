/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int len = heights.size();
    int pos = 0;
    priority_queue<int> q;
    for(;pos < len - 1; pos += 1) {
      // cout << pos << ' ' << bricks << ' ' << ladders << endl;
      int diff = heights[pos + 1] - heights[pos];
      if(diff <= 0) {
        continue;
      }
      if(diff <= bricks) {
        bricks -= diff;
        q.push(diff);
      } else {
        if(!ladders) break;
        if(q.size() && q.top() > diff) {
          bricks += q.top() - diff;
          q.pop();
          q.push(diff);
        }
        ladders -= 1;
      }
    }
    return pos;
  }
};
// @lc code=end

