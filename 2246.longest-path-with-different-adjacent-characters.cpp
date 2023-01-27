/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution {
  vector<vector<int>> neighbors;
  int answer = 0;
  int dfs(int current, const string &s) {
    int mmax1 = 0;
    int mmax2 = 0;
    for(auto next : neighbors[current]) {
      int l = dfs(next, s);
      answer = max(answer, l);
      if(s[next] == s[current]) continue;
      if(l > mmax1) {
        mmax2 = mmax1;
        mmax1 = l;
      } else {
        mmax2 = max(mmax2, l);
      }
    }
    answer = max(answer, 1 + mmax1 + mmax2);
    return 1 + mmax1;
  }
public:
  int longestPath(vector<int>& parent, string s) {
    int len = parent.size();
    neighbors.resize(len);
    for(int i = 1; i < len; ++i) {
      neighbors[parent[i]].push_back(i);
    }
    dfs(0, s);
    return answer;
  }
};

// Accepted
// 141/141 cases passed (392 ms)
// Your runtime beats 93.15 % of cpp submissions
// Your memory usage beats 71.15 % of cpp submissions (181.1 MB)
// @lc code=end

