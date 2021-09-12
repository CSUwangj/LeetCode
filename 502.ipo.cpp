/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
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
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int len = profits.size();
    map<int, multiset<int>> projects;
    for(int i = 0; i < len; ++i) {
      projects[capital[i]].insert(profits[i]);
    }

    if(projects.begin()->first > w) return 0;
    if(projects.rbegin()->first < w) {
      sort(profits.begin(), profits.end(), greater<int>());
      for(int i = 0; i < min(k, len); ++i) w += profits[i];
      return w;
    }
    auto it = projects.begin();
    priority_queue<int> pq;
    int count = 0;
    while(count < k && it != projects.end()) {
      while(it != projects.end() && it->first <= w) {
        for(auto profit : it->second) {
          pq.push(profit);
        }
        ++it;
      }
      if(pq.empty()) {
        break;
      }
      w += pq.top();
      pq.pop();
      count += 1;
    }
    while(count < k && pq.size()) {
      w += pq.top();
      pq.pop();
      count += 1;
    }

    return w;
  }
};

// Accepted
// 35/35 cases passed (717 ms)
// Your runtime beats 5.14 % of cpp submissions
// Your memory usage beats 6.91 % of cpp submissions (118.5 MB)
// @lc code=end

