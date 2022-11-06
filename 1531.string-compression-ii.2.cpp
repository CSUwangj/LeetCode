/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

// @lc code=start
class Solution {
  uint8_t memo[104][104];
  string s;
  uint8_t solve(uint8_t pos, uint8_t to_delete) {
    if(memo[pos][to_delete] != 255) {
      return memo[pos][to_delete];
    }
    if(pos + to_delete >= s.length()) {
      return memo[pos][to_delete] = 0;
    }
    uint8_t result = 255;
    uint8_t origin_to_delete = to_delete;
    if(to_delete) {
      result = solve(pos + 1, to_delete - 1);
    }
    uint8_t count = 1;
    for(int i = pos + 1; i <= s.length(); ++i) {
      uint8_t add = count == 100 ? 4 :
                    count >  9   ? 3 :
                    count >  1   ? 2 :
                    1;
      result = min<uint8_t>(result, solve(i, to_delete) + add);
      if(i == s.size()) break;
      if(s[i] != s[pos] && !to_delete) break;
      if(s[i] == s[pos]) {
        count += 1;
      } else {
        to_delete -= 1;
      }
    }
    return memo[pos][origin_to_delete] = result;
  }
public:
  int getLengthOfOptimalCompression(string s, int k) {
    this->s = s;
    memset(memo, -1, sizeof(memo[0]) * (s.length() + 1));
    return solve(0, k);
  }
};

// Accepted
// 136/136 cases passed (24 ms)
// Your runtime beats 97.73 % of cpp submissions
// Your memory usage beats 90.15 % of cpp submissions (6.3 MB)
// @lc code=end

