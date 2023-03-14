/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minJumps(vector<int>& arr) {
    if(arr.size() < 3) return arr.size() - 1;
    map<int, vector<int>> positions;
    set<int> numVisit;
    int len = arr.size();
    vector<bool> posVisit(len);
    for(int i = 0; i < len; ++i) {
      positions[arr[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    posVisit[0] = true;

    while(q.size()) {
      auto [cnt, pos] = q.front();
      if(pos == len - 1) return cnt;
      q.pop();
      if(pos && !posVisit[pos - 1]) {
        q.push({cnt + 1, pos - 1});
        posVisit[pos - 1] = true;
      }
      if(pos < len - 1 && !posVisit[pos + 1]) {
        q.push({cnt + 1, pos + 1});
        posVisit[pos + 1] = true;
      }
      int num = arr[pos];
      if(numVisit.count(num)) continue;
      numVisit.insert(num);
      for(auto next : positions[num]) {
        if(next == pos) continue;
        posVisit[next] = true;
        q.push({cnt + 1, next});
      }
    }
    return - 1;
  }
};

// Accepted
// 33/33 cases passed (238 ms)
// Your runtime beats 64.24 % of cpp submissions
// Your memory usage beats 42.53 % of cpp submissions (80.1 MB)
// @lc code=end
