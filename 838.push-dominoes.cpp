/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
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
  string pushDominoes(string dominoes) {
    int len = dominoes.length();
    bool prevLeft = true;
    int prevPos = -1;
    for(int i = 0; i < len; ++i) {
      if(dominoes[i] == '.') continue;
      if(dominoes[i] == 'L') {
        if(prevLeft) {
          for(int j = prevPos + 1; j < i; ++j) dominoes[j] = 'L';
        } else {
          for(int left = prevPos + 1, right = i - 1; left < right; ++left, --right) {
            dominoes[left] = 'R';
            dominoes[right] = 'L';
          }
        }
        prevLeft = true;
        prevPos = i;
      } else {
        if(!prevLeft) for(int j = prevPos + 1; j < i; j++) dominoes[j] = 'R';
        prevLeft = false;
        prevPos = i;
      }
    }
    if(!prevLeft) {
      for(int i = prevPos + 1; i < len; ++i) dominoes[i] = 'R';
    }
    return dominoes;
  }
};

// Accepted
// 43/43 cases passed (21 ms)
// Your runtime beats 99.83 % of cpp submissions
// Your memory usage beats 94.28 % of cpp submissions (12.7 MB)
// @lc code=end

