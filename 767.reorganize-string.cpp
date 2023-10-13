/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
  using pi = pair<int, int>;
public:
  string reorganizeString(string s) {
    int cnt[26] = {};
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }
    priority_queue<pi> pq;

    for(int i = 0; i < 26; ++i) {
      if(cnt[i]) pq.push({cnt[i], i});
    }
    if(pq.top().first > s.length() - pq.top().first + 1) return "";

    string answer;
    while(pq.size()) {
      auto [cnt, c] = pq.top();
      pq.pop();
      answer.push_back(c + 'a');
      if(pq.size()) {
        auto [cnt2, c2] = pq.top();
        pq.pop();
        answer.push_back(c2 + 'a');
        if(cnt2 > 1) pq.push({cnt2 - 1, c2});
      }
      if(cnt > 1) pq.push({cnt - 1, c});
    }
    return answer;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.07 % of cpp submissions (6.3 MB)
// @lc code=end

