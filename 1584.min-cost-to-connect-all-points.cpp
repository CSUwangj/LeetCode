/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  using pi = pair<int, int>;
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int len = points.size();
    vector<bool> connected(len);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    connected[0] = true;
    for(int i = 1; i < len; ++i) {
      pq.push({abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]), i});
    }
    int answer = 0;
    int rest = len - 1;
    while(pq.size() && rest) {
      auto [cost, point] = pq.top();
      pq.pop();
      if(connected[point]) continue;
      connected[point] = true;
      answer += cost;
      rest -= 1;
      for(int i = 1; i < len; ++i) {
        if(connected[i]) continue;
        pq.push({abs(points[i][0] - points[point][0]) + abs(points[i][1] - points[point][1]), i});
      }
    }
    return answer;
  }
};

// Accepted
// 72/72 cases passed (199 ms)
// Your runtime beats 84.16 % of cpp submissions
// Your memory usage beats 76.71 % of cpp submissions (42.3 MB)
// @lc code=end
