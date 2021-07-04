/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
using pi = pair<int, int>;
class Solution {
public:
  int candy(vector<int>& ratings) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = ratings.size();
    vector<int> candy(len);
    for(int i = 0; i < len; ++i) {
      pq.push({ratings[i], i});
    }
    while(pq.size()) {
      auto [rating, pos] = pq.top();
      // cout << pos << ' ' << rating << ' ';
      pq.pop();
      candy[pos] = 1;
      if(pos && ratings[pos - 1] < rating) {
        candy[pos] = max(candy[pos], candy[pos - 1] + 1);
      }
      if(pos < len - 1 && ratings[pos + 1] < rating) {
        candy[pos] = max(candy[pos], candy[pos + 1] + 1);
      }
      // cout << pos << ' ' << candy[pos] << endl;
    }
    return accumulate(candy.begin(), candy.end(), 0);
  }
};
// @lc code=end

