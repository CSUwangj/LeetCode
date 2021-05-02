/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 */

// @lc code=start
class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    if(x == 1 && y == 1) {
      if(bound >= 2) return {2};
      return {};
    }
    if(x == 1 || y == 1) {
      int rest = x == 1 ? y : x;
      int cur = 1;
      vector<int> answer;
      while(cur + 1 <= bound) {
        answer.push_back(cur + 1);
        cur *= rest;
      }
      return answer;
    }
    unordered_set<int> answer;
    for(int i = 1; i + 1 <= bound; i *= x) {
      for(int j = 1; j + i <= bound; j *= y) {
        answer.insert(i + j);
      }
    }
    return vector<int>(answer.begin(), answer.end()); 
  }
};
// @lc code=end

