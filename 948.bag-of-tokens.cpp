/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int head = 0, tail = tokens.size();
    int ans = 0, cur = 0;
    while(head != tail) {
      while(head != tail && P >= tokens[head]) {
        P -= tokens[head];
        cur += 1;
        head += 1;
      }
      ans = max(ans, cur);
      if(!cur || head == tail) break;
      tail -= 1;
      cur -= 1;
      P += tokens[tail];
    }
    return ans;
  }
};

// Accepted
// 147/147 cases passed (13 ms)
// Your runtime beats 35.25 % of cpp submissions
// Your memory usage beats 27.39 % of cpp submissions (10.7 MB)
// @lc code=end

