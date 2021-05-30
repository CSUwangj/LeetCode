/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
int prefix(string &pre, string &post) {
  int lPre = pre.length();
  int lPost = post.length();
  for(int len = min(lPre, lPost); len; --len) {
    bool ok = true;
    for(int i = 0; ok && i < len; ++i) {
      ok = pre[lPre - len + i] == post[i];
    }
    if(ok) return len;
  }
  return 0;
}
class Solution {
  int n;
  vector<int> len;
  vector<vector<int>> overlap;
  vector<unordered_map<int, int>> dp;
  vector<unordered_map<int, int>> next;

  void init(vector<string>& words) {
    n = words.size();
    dp.resize(n);
    len.resize(n);
    next.resize(n);
    overlap.resize(n, vector<int>(n));

    for(int i = 0; i < n; ++i) {
      len[i] = words[i].length();
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j) continue;
        overlap[i][j] = prefix(words[i], words[j]);
      }
    }
  }

  int solve(int idx, int mask) {
    // cout << idx << ' '<< mask<<endl;
    if(mask == (1 << n) - 1) return 0;
    if(dp[idx].count(mask)) return dp[idx][mask];
    dp[idx][mask] = INT_MAX;
    for(int i = 0; i < n; i++) {
      if(!(mask & (1 << i))) {
        int tmp = len[i] - overlap[idx][i] + solve(i, mask | (1 << i));
        if(tmp < dp[idx][mask]) {
          dp[idx][mask] = tmp;
          next[idx][mask] = i;
        }
      }
    }
    
    return dp[idx][mask];
  }

  string construct(vector<string>& words, int start) {
    int index = start;
    string answer = words[index];
    int state = 1 << index;
    while(state != (1 << n) - 1) {
      int nextIndex = next[index][state];
      answer += words[nextIndex].substr(overlap[index][nextIndex]);
      index = nextIndex;
      state |= 1 << nextIndex;
    }
    return answer;
  }
public:
  string shortestSuperstring(vector<string>& words) {
    init(words);
    int minLength = INT_MAX;
    int start = -1;
    for(int i = 0; i < n; ++i) {
      int cur = len[i] + solve(i, 1 << i);
      if(minLength > cur) {
        minLength = cur;
        start = i;
      }
    }
    
    return construct(words, start);
  }
};
// @lc code=end

