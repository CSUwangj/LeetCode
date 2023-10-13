/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution {
  bool denotes(const vector<int> &a, const vector<int> &b) {
    return 1LL * a[2] * a[2] >= 1LL * (a[0] - b[0]) * (a[0] - b[0]) + 1LL * (a[1] - b[1]) * (a[1] - b[1]);
  }
public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int sz = bombs.size();
    vector<vector<int>> neighbors(sz);
    for(int i = 0; i < sz; ++i) {
      for(int j = 0; j < sz; ++j) {
        if(i == j) continue;
        if(denotes(bombs[i], bombs[j])) {
          neighbors[i].push_back(j);
        }
      }
    }

    int answer = 1;
    for(int i = 0; i < sz; ++i) {
      queue<int> q;
      vector<bool> denote(sz);
      q.push(i);
      denote[i] = true;
      int result = 0;
      while(q.size()) {
        int current = q.front();
        q.pop();
        result += 1;
        for(auto next : neighbors[current]) {
          if(denote[next]) continue;
          denote[next] = true;
          q.push(next);
        }
      }
      answer = max(result, answer);
    }

    return answer;
  }
};

// Accepted
// 160/160 cases passed (139 ms)
// Your runtime beats 65.36 % of cpp submissions
// Your memory usage beats 34.41 % of cpp submissions (21.4 MB)
// @lc code=end

