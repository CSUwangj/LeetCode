/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
  int len;
  void dfs(
    vector<vector<int>> &answer,
    vector<int> &cur,
    vector<int> &candidates,
    int rest,
    int index
  ) {
    // cout << rest << ' ' << index << endl;
    if(!rest) {
      answer.push_back(cur);
      return;
    }
    if(index == len) return;
    for(int i = index; i < len; ++i) {
      if(candidates[i] <= rest) {
        cur.push_back(candidates[i]);
        dfs(answer, cur, candidates, rest - candidates[i], i + 1);
        cur.pop_back();
      }
    }
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    len = candidates.size();
    sort(candidates.rbegin(), candidates.rend());
    vector<vector<int>> answer;
    vector<int> tmp;
    dfs(answer, tmp, candidates, target, 0);
    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};

// Accepted
// 174/174 cases passed (532 ms)
// Your runtime beats 16.38 % of cpp submissions
// Your memory usage beats 34.76 % of cpp submissions (11.6 MB)
// @lc code=end

