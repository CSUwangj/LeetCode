/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
using pi = pair<int, int>;
class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    target.resize(unique(target.begin(), target.end()) - target.begin());
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = target.size();
    for(int i = 0; i < len; i++) {
      pq.push({target[i], i});
    }
    vector<pi> intervals{{0, len - 1}};
    vector<pi> tmp;
    int current = 0;
    int answer = 0;
    while(pq.size() && intervals.size()) {
      auto [val, pos] = pq.top();
      pq.pop();
      if(val != current) {
        for(auto [begin, end] : intervals) {
          answer += (val - current);
        }
        current = val;
      }
      for(auto [begin, end] : intervals) {
        if(begin <= pos && end >= pos) {
          if(begin == pos) {
            tmp.push_back({begin + 1, end});
          } else if(end == pos) {
            tmp.push_back({begin, end - 1});
          } else {
            tmp.push_back({begin, pos - 1});
            tmp.push_back({pos + 1, end});
          }
        } else {
          tmp.push_back({begin, end});
        }
      }
      intervals.clear();
      for(auto [begin, end] : tmp) {
        if(begin == end) {
          answer += target[begin] - current;
        } else {
          intervals.push_back({begin, end});
        }
      }
      tmp.clear();
    }

    return answer;
  }
};

// TLE
// @lc code=end

