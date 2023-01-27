/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
  using pi = pair<int, int>;
  vector<vector<pi>> neighbors;
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    neighbors.resize(n);
    for(const auto &flight : flights) {
      neighbors[flight[0]].push_back({flight[1], flight[2]});
    }

    vector<int> costs(n, INT_MAX);
    queue<pi> q;

    q.push({0, src});
    k += 1; // k stops means path contains at most k + 2 cities
    while(q.size() && k--) {
      int sz = q.size();
      // cout << k << ':' << sz << endl;
      for(int _ = 0; _ < sz; ++_) {
        auto [cost, current] = q.front();
        q.pop();
        for(const auto &[next, price] : neighbors[current]) {
          if(cost + price >= costs[next]) continue;
          costs[next] = cost + price;
          q.push({cost + price, next});
        }
      }
    }

    return costs[dst] == INT_MAX ? -1 : costs[dst];
  }
};

// Accepted
// 52/52 cases passed (32 ms)
// Your runtime beats 59.58 % of cpp submissions
// Your memory usage beats 75.69 % of cpp submissions (13.1 MB)
// @lc code=end

