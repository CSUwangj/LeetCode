/*
 * @lc app=leetcode id=1606 lang=cpp
 *
 * [1606] Find Servers That Handled Most Number of Requests
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
using pii = pair<int, int>;
class Solution {
public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    set<int> ok;
    for(int i = 0; i < k; ++i) ok.insert(i);
    
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> count(k);
    int len = arrival.size();
    for(int i = 0; i < len; ++i) {
      while(!q.empty() && q.top().first <= arrival[i]) {
        ok.insert(q.top().second);
        q.pop();
      }
      if(ok.empty()) continue;
      auto it = ok.lower_bound(i % k);
      it = it == ok.end() ? ok.begin() : it;
      int server = *it;
      count[server] += 1;
      ok.erase(server);
      q.push(make_pair(arrival[i] + load[i], server));
    }
    
    int maxRequest = *max_element(count.begin(), count.end());
    vector<int> answer;
    for(int i = 0; i < k; ++i) if(count[i] == maxRequest) answer.push_back(i);
    
    return answer;
  }
};

// Accepted
// 108/108 cases passed (308 ms)
// Your runtime beats 87.5 % of cpp submissions
// Your memory usage beats 68.45 % of cpp submissions (118.1 MB)
// @lc code=end

