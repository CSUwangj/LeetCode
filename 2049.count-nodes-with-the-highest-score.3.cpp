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
  void dfs(int cur, int *count, int children[][2]) {
    int left = 1;
    int right = 1;
    count[cur] = 1;
    if(children[cur][0]) {
      dfs(children[cur][0], count, children);
      count[cur] += count[children[cur][0]];
    }
    if(children[cur][1]) {
      dfs(children[cur][1], count, children);
      count[cur] += count[children[cur][1]];
    }
  }
public:
  int countHighestScoreNodes(vector<int>& parents) {
    int len = parents.size();
    int count[len];
    int children[len][2];
    memset(children, 0, sizeof(children));
    for(int i = 1; i < len; ++i) {
      if(children[parents[i]][0]) {
        children[parents[i]][1] = i;
      } else {
        children[parents[i]][0] = i;
      }
    }
    dfs(0, count, children);

    long scores[len];
    for(int i = 0; i < len; ++i) {
      int left = 0;
      int right = 0;
      if(children[i][0]) left = count[children[i][0]];
      if(children[i][1]) right = count[children[i][1]];
      int upper = len - left - right - 1;
      scores[i] = 1L * max(upper, 1) * max(left, 1) * max(right, 1);
    }
    long score = *max_element(scores, scores + len);
    int answer = 0;
    for(auto s : scores) {
      answer += s == score;
    }
    return answer;
  }
};

// Accepted
// 206/206 cases passed (125 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.83 % of cpp submissions (71.9 MB)
// @lc code=end
