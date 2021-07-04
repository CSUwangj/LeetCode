/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
  int maxProduct(vector<string>& words) {
    int sz = words.size();
    vector<int> mask(sz);
    vector<int> len(sz);
    for(int i = 0; i < sz; ++i) {
      for(auto c : words[i]) mask[i] |= (1 << (c - 'a'));
      len[i] = words[i].length();
    }
    int answer = 0;
    for(int i = 0; i < sz - 1; ++i) {
      for(int j = i + 1; j < sz; ++j) {
        if(!(mask[i] & mask[j])) answer = max(answer, len[i] * len[j]);
      }
    }
    return answer;
  }
};
// @lc code=end
