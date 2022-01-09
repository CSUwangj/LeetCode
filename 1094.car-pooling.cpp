/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> people;
    people.reserve(trips.size() * 2);
    for(auto &trip : trips) {
      people.push_back({trip[1], trip[0]});
      people.push_back({trip[2], -trip[0]});
    }
    sort(people.begin(), people.end());
    for(auto [_, people] : people) {
      capacity -= people;
      if(capacity < 0) return false;
    }

    return true;
  }
};

// Accepted
// 58/58 cases passed (9 ms)
// Your runtime beats 78.76 % of cpp submissions
// Your memory usage beats 95.84 % of cpp submissions (9.8 MB)
// @lc code=end
