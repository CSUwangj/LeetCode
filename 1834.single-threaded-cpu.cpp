/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution {
  using pi = pair<int, int>;
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int len = tasks.size();
    vector<int> indice(len);
    for(int i = 0; i < len; ++i) {
      indice[i] = i;
    }
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return tasks[a] < tasks[b];
    });
    vector<int> answer;
    answer.reserve(len);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    unsigned int current = 0;
    int pos = 0;
    while(pos < len) {
      if(pq.size()) {
        auto [processing, index] = pq.top();
        pq.pop();
        current = max<unsigned int>(current, tasks[index][0]) + processing;
        answer.push_back(index);
      }
      if(current < tasks[indice[pos]][0] && pq.empty()) {
        pq.push({tasks[indice[pos]][1], indice[pos]});
        pos += 1;
        continue;
      }
      while(pos < len && current >= tasks[indice[pos]][0]) {
        pq.push({tasks[indice[pos]][1], indice[pos]});
        pos += 1;
      }
    }
    while(pq.size()) {
      auto [_processing, index] = pq.top();
      pq.pop();
      answer.push_back(index);
    }
    return answer;
  }
};

// Accepted
// 39/39 cases passed (596 ms)
// Your runtime beats 94.18 % of cpp submissions
// Your memory usage beats 97.88 % of cpp submissions (114.8 MB)
// @lc code=end

