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

pair<int, int> projects[100000];
class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int len = profits.size();
    for(int i = 0; i < len; ++i) {
      projects[i].first = capital[i];
      projects[i].second = profits[i];
    }
    sort(projects, projects + len);
    
    priority_queue<int> pq;
    for(int pos = 0, end = len; k; --k) {
      while(pos < len && projects[pos].first <= w) {
        pq.push(projects[pos].second);
        pos += 1;
      }
      if(pq.empty()) break;
      w += pq.top();
      pq.pop();
    }

    return w;
  }
};

// Accepted
// 35/35 cases passed (132 ms)
// Your runtime beats 97.11 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (74.9 MB)
// @lc code=end

