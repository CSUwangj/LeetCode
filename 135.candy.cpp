/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
using pi = pair<int, int>;
int cd[20000];
class Solution {
public:
  int candy(vector<int>& ratings) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = ratings.size();
    for(int i = 0; i < len; ++i) {
      pq.push({ratings[i], i});
      cd[i] = 0;
    }
    while(pq.size()) {
      auto [rating, pos] = pq.top();
      pq.pop();
      if(cd[pos]) continue;
      cd[pos] = 1;
      for(int i = pos + 1; i < len; ++i) {
        if(ratings[i] <= ratings[i - 1]) break;
        if(cd[i] > cd[i - 1] + 1) break;
        cd[i] = cd[i - 1] + 1;
      }
      for(int i = pos - 1; i >= 0; --i) {
        if(ratings[i] <= ratings[i + 1]) break;
        if(cd[i] > cd[i + 1] + 1) break;
        cd[i] = cd[i + 1] + 1;
      }
    }
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      // cout << cd[i] << ' ';
      answer += cd[i];
    }
    // cout << endl;
    return answer;
  }
};
// @lc code=end

