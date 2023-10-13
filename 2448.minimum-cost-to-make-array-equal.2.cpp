/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
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
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int len = nums.size();
    vector<pair<int, int>> pairs;
    pairs.reserve(len);
    for(int i = 0; i < len; ++i) {
      pairs.push_back({nums[i], cost[i]});
    }
    sort(pairs.begin(), pairs.end());

    long long costs = 0;
    long long addOneCost = pairs[0].second;
    long long minusOneCost = 0;
    for(int i = len - 1; i > 0; --i) {
      costs += 1LL * (pairs[i].first - pairs[0].first) * (pairs[i].second);
      minusOneCost += pairs[i].second;
    }
    long long answer = costs;
    for(int i = 1; i < len; addOneCost += pairs[i].second, minusOneCost -= pairs[i].second, ++i) {
      if(pairs[i].first == pairs[i - 1].first) {
        continue;
      }
      int diff = pairs[i].first - pairs[i - 1].first;
      costs += 1LL * diff * addOneCost;
      costs -= 1LL * diff * minusOneCost;
      answer = min(costs, answer);
    }

    return answer;
  }
};

// Accepted
// 48/48 cases passed (92 ms)
// Your runtime beats 89.42 % of cpp submissions
// Your memory usage beats 47.08 % of cpp submissions (40.8 MB)
// @lc code=end

