/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

// @lc code=start
class Solution {
  uint8_t memo[101][27][101][104] = {};
  string s;
  uint8_t solve(
    uint8_t pos,
    uint8_t last,
    uint8_t last_length,
    uint8_t to_delete
  ) {
    if(memo[pos][last][last_length][to_delete] != 255) {
      
      return memo[pos][last][last_length][to_delete];
    }
    if(pos + to_delete >= s.length()) {
      uint8_t add = !last_length ? 0 :
                    last_length == 1 ? 1 :
                    last_length < 10 ? 2 :
                    last_length < 100 ? 3 : 4;
      return memo[pos][last][last_length][to_delete] = add;
    }
    uint8_t result = 255;
    if(to_delete) {
      result = solve(pos + 1, last, last_length, to_delete - 1);
    }
    if(s[pos] - 'a' == last) {
      result = min(result, solve(pos + 1, last, last_length + 1, to_delete));
    } else {
      uint8_t add = !last_length ? 0 :
                    last_length == 1 ? 1 :
                    last_length < 10 ? 2 :
                    last_length < 100 ? 3 : 4;
      result = min<uint8_t>(result, add + solve(pos + 1, s[pos] - 'a', 1, to_delete));
    }
    return memo[pos][last][last_length][to_delete] = result;
  }
public:
  int getLengthOfOptimalCompression(string s, int k) {
    this->s = s;
    memset(memo, -1, sizeof(memo[0]) * (s.length() + 1));
    return solve(0, 26, 0, k);
  }
};

// Accepted
// 136/136 cases passed (517 ms)
// Your runtime beats 37.12 % of cpp submissions
// Your memory usage beats 29.54 % of cpp submissions (37.7 MB)
// @lc code=end

