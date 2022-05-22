/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<vector<int>> poorerThan;
  vector<int> degree;
public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int len = quiet.size();
    vector<int> answer(len);
    poorerThan.resize(len);
    degree.resize(len);
    for(int i = 0; i < len; ++i) {
      answer[i] = i;
    }
    for(const auto &r : richer) {
      poorerThan[r[0]].push_back(r[1]);
      degree[r[1]] += 1;
    }
    queue<int> q;
    for(int i = 0; i < len; ++i) {
      if(!degree[i]) {
        q.push(i);
      }
    }
    while(q.size()) {
      auto cur = q.front();
      q.pop();
      for(auto lessRich : poorerThan[cur]) {
        degree[lessRich] -= 1;
        if(!degree[lessRich]) {
          q.push(lessRich);
        }
        if(quiet[answer[lessRich]] > quiet[answer[cur]]) {
          answer[lessRich] = answer[cur];
        }
      }
    }
    return move(answer);
  }
};

// Accepted
// 86/86 cases passed (117 ms)
// Your runtime beats 82.27 % of cpp submissions
// Your memory usage beats 58.01 % of cpp submissions (42.8 MB)
// @lc code=end
