/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
public:
  string decodeAtIndex(string S, int K) {
    char prevChar = S[0];
    int len = S.length();
    vector<unsigned long long> cnt(len);
    vector<char> lastChar(len);
    cnt[0] = 1, lastChar[0] = S[0];
    for(int i = 1; i < len; ++i) {
      if(isdigit(S[i])) {
        cnt[i] = cnt[i-1] * (S[i]-'0');
      } else {
        cnt[i] = cnt[i-1] + 1;
        prevChar = S[i];
      }
      lastChar[i] = prevChar;
    }
    if(K >= cnt.back()) K %= cnt.back();
    if(K == 0) return string(1, prevChar);
    while(K) {
      int pos = 0;
      while(pos < len && cnt[pos] < K) ++pos;
      if(cnt[pos] == K || K % cnt[pos-1] == 0) return string(1, lastChar[pos]);
      K %= cnt[pos-1];
    }
    return "";
  }
};

// Accepted
// 45/45 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.16 % of cpp submissions (6.6 MB)
// @lc code=end

