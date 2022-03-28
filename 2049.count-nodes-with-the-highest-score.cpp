/*
 * @lc app=leetcode id=2049 lang=cpp
 *
 * [2049] Count Nodes With the Highest Score
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
  int countHighestScoreNodes(vector<int>& parents) {
    int len = parents.size();
    vector<int> degree(len);
    for(int i = 1; i < len; ++i) {
      degree[parents[i]] += 1;
    }
    queue<int> nodes;
    for(int i = 0; i < len; ++i) {
      if(!degree[i]) nodes.push(i);
    }
    vector<pair<long, long>> subCount(len);
    while(nodes.size()) {
      int cur = nodes.front();
      nodes.pop();
      if(!cur) continue;
      int count = 1 + subCount[cur].first + subCount[cur].second;
      if(subCount[parents[cur]].first) {
        subCount[parents[cur]].second = count;
      } else {
        subCount[parents[cur]].first = count;
      }
      degree[parents[cur]] -= 1;
      if(!degree[parents[cur]]) {
        nodes.push(parents[cur]);
      }
    }

    int answer = 0;
    long maxScore = 0;
    for(int i = 0; i < len; ++i) {
      int upper = max(1L, len - subCount[i].first - subCount[i].second - 1);
      int left = max(1L, subCount[i].first);
      int right = max(1L, subCount[i].second);
      long score = 1L * upper * left * right;
      if(score > maxScore) {
        answer = 0;
        maxScore = score;
      }
      answer += score == maxScore;
    }
    return answer;
  }
};

// Accepted
// 206/206 cases passed (158 ms)
// Your runtime beats 99.66 % of cpp submissions
// Your memory usage beats 98.62 % of cpp submissions (81.7 MB)
// @lc code=end
