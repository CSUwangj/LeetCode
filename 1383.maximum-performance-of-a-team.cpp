/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<int> index(n);
    for (int i = 0; i < n; ++i) index[i] = i;
    sort(index.begin(), index.end(), [&](int a, int b) { 
      return efficiency[a] > efficiency[b] || (efficiency[a] == efficiency[b] && speed[a] > speed[b]);
    });
    priority_queue<int, vector<int>, greater<int>> q;
    int ef = INT_MAX;
    long long sum = 0;
    long long answer = 0;
    for(int i = 0; i < n; ++i) {
      int idx = index[i];
      if(q.size() < k) {
        sum += speed[idx];
        ef = min(ef, efficiency[idx]);
        answer = max(answer, sum * ef);
        q.push(speed[idx]);
      } else {
        if(q.top() >= speed[idx]) continue;
        sum += speed[idx] - q.top();
        q.pop();
        q.push(speed[idx]);
        ef = min(ef, efficiency[idx]);
        answer = max(answer, sum * ef);
      }
    }
    return answer % MOD;
  }
};
// @lc code=end

