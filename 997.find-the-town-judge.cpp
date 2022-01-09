/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
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
  int findJudge(int n, vector<vector<int>>& trust) {
    int outDegree[n + 1];
    int inDegree[n + 1];
    memset(inDegree, 0, sizeof(inDegree));
    memset(outDegree, 0, sizeof(outDegree));
    for(auto &t : trust) {
      outDegree[t[0]] += 1;
      inDegree[t[1]] += 1;
    }
    int answer = -1;
    for(int i = 1; i <= n; ++i) {
      if(inDegree[i] == n - 1 && !outDegree[i]) {
        if(answer != -1) return -1;
        answer = i;
      }
    }
    return answer;
  }
};

// Accepted
// 92/92 cases passed (136 ms)
// Your runtime beats 98.09 % of cpp submissions
// Your memory usage beats 97.72 % of cpp submissions (60.5 MB)
// @lc code=end
