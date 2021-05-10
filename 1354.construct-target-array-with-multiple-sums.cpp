/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */

// @lc code=start
class Solution {
public:
  bool isPossible(vector<int>& target) {
    if(target.size() == 1 && target[0] != 1) return false;
    priority_queue<int> q;
    long long sum = 0;
    for(auto i : target) {
      q.push(i);
      sum += i;
    }
    // cout << "###########" << endl;
    while(q.size() && q.top() != 1) {
      long long cur = q.top();
      q.pop();
      long long nxt = q.top();
      long long diff = ceil(1.0 * (cur - nxt) / (sum - cur)) * (sum - cur);
      if(cur - diff == nxt && nxt != 1) diff += (sum - cur); 
      // cout << cur << ' ' << diff << endl;
      cur -= diff;
      sum -= diff;
      if(cur < 1) return false;
      q.push(cur);
    }
    return true;
  }
};

// cur - x * diff < nxt
// (cur - nxt) / diff
// @lc code=end


