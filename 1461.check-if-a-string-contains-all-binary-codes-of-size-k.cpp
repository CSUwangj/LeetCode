/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int len = s.length();
    if((1 << k) > len - k + 1) return false;
    int cur = 0;
    const int MASK = (1 << k) - 1;
    vector<bool> has(1 << k);
    for(int i = 0; i < k; ++i) {
      cur <<= 1;
      cur |= (s[i] == '1');
    }
    has[cur] = true;
    for(int i = k; i < len; ++i) {
      cur <<= 1;
      cur |= (s[i] == '1');
      cur &= MASK;
      has[cur] = true;
    }
    for(auto b : has) if(!b) return false;
    return true;
  }
};

// Accepted
// 200/200 cases passed (92 ms)
// Your runtime beats 88.99 % of cpp submissions
// Your memory usage beats 99.37 % of cpp submissions (17.4 MB)
// @lc code=end

