/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
  using pi = pair<int, int>;
public:
  bool canCross(vector<int>& stones) {
    if(stones[1] != 1) return false;
    int target = stones.back();
    set<int> s(stones.begin(), stones.end());
    set<pi> ways;
    queue<pi> q;
    q.push({1, 1});
    while(q.size()) {
      auto [jump, pos] = q.front();
      q.pop();
      if(pos == target) return true;
      for(int i = jump - 1; i < jump + 2; ++i) {
        if(!i) continue;
        if(!s.count(pos + i)) continue;
        if(ways.count({i, pos + i})) continue;
        ways.insert({i, pos + i});
        q.push({i, pos + i});
      }
    }

    return false;
  }
};

// Accepted
// 52/52 cases passed (192 ms)
// Your runtime beats 47.07 % of cpp submissions
// Your memory usage beats 62.79 % of cpp submissions (36.6 MB)
// @lc code=end
