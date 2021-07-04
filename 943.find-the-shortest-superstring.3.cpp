/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
const int SZ = (1 << 12);

int pre[SZ][12];
int overlap[12][12];

using ti = tuple<int, int, int, int>;

void init(vector<string> &words) {
  int len = words.size();
  for(int i = 0; i < len; ++i) {
    for(int j = 0; j < len; ++j) {
      if(i == j) continue;
      overlap[i][j] = 0;
      for(int k = min(words[i].length(), words[j].length()) - 1; k > 0; --k) {
        if(words[i].substr(words[i].length() - k) == words[j].substr(0, k)) {
          overlap[i][j] = k;
          break;
        }
      }
    }
  }
}

string constructAnswer(vector<string> &words, int state, int last) {
  string answer = words[last];
  while(pre[state][last] != -1) {
    int p = pre[state][last];
    state ^= (1 << last);
    answer = words[p].substr(0, words[p].length() - overlap[p][last]) + answer;
    last = p;
  }
  return answer;
}

string solve(vector<string> &words) {
  memset(pre, -1, sizeof(pre));
  priority_queue<ti, vector<ti>, greater<ti>> pq;
  int len = words.size();
  int target = (1 << len) - 1;
  for(int i = 0; i < len; ++i) {
    pq.push({words[i].length(), 1 << i, -1, i});
  }
  while(pq.size()) {
    auto [length, state, p, last] = pq.top();
    // cout << length << " " << state <<  " " << p << " " << last  << endl;
    pq.pop();
    if(pre[state][last] != -1) continue;
    pre[state][last] = p;
    if(state == target) return constructAnswer(words, state, last);
    for(int i = 0; i < len; ++i) {
      if(state & (1 << i)) continue;
      pq.push({length + words[i].length() - overlap[last][i], state | (1 << i), last, i});
    }
  }
  return "";
}
class Solution {
public:
  string shortestSuperstring(vector<string>& words) {
    init(words);    
    return solve(words);
  }
};
// @lc code=end

