/*
 * @lc app=leetcode id=1718 lang=cpp
 *
 * [1718] Construct the Lexicographically Largest Valid Sequence
 */

// @lc code=start
class Solution {
  vector<bool> vis;
  vector<int> answer;
  int n;
  bool solve(int index) {
    if(index == 2 * n - 1) return true;
    // cout << "#" << answer << endl;
    if(answer[index]) return solve(index + 1);
    for(int i = min(n, 2 * n - 2 - index); i > 1 ; --i) {
      // cout << index << ' ' << i << endl;
      if(vis[i]) continue;
      // cout << "???" << endl;
      if(i != 1 && answer[i + index]) continue;
      // cout << "????" << endl;
      answer[index] = i;
      answer[index + i] = i;
      vis[i] = true;
      if(solve(index + 1)) return true;
      answer[index] = 0;
      answer[index + i] = 0;
      vis[i] = false;
    }
    if(!vis[1]) {
      answer[index] = 1;
      vis[1] = true;
      if(solve(index + 1)) return true;
      vis[1] = false;
      answer[index] = 0;
    }
    return false;
  }
public:
  vector<int> constructDistancedSequence(int n) {
    this->n = n;
    vis.resize(n + 1);
    answer.resize(n * 2 - 1);
    solve(0);
    return answer;
  }
};
// @lc code=end

