/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
const int N = 6;
inline int match(const string &a, const string &b) {
  int result = 0;
  for(int i = 0; i < 6; ++i) {
    result += a[i] == b[i];
  }
  return result;
}
class Solution {
  vector<vector<int>> adj;
  int len;
  void init(vector<string> & wordlist) {
    len = wordlist.size();
    adj.resize(len, vector<int>(len));
    for(int i = 0; i < len; ++i) {
      for(int j = i + 1; j < len; ++j) {
        adj[i][j] = adj[j][i] = match(wordlist[i], wordlist[j]);
      }
    }
    for(int i = 0; i < len; ++i) {
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        adj[i][i] += adj[i][j];
      }
    }
  }

  int getNextGuess() {
    int idx = -1;
    int maxAdj = -1;
    for(int i = 0; i < len; ++i) {
      if(adj[i][i] > maxAdj) {
        idx = i;
        maxAdj = adj[i][i];
      }
    }
    return idx;
  }

  void pruneGuess(int idx, int guess) {
    vector<int> toRemove{idx};
    if(!guess) {
      for(int i = 0; i < len; ++i) {
        if(adj[i][idx] > 0) toRemove.push_back(i);
      }
    } else {
      for(int i = 0; i < len; ++i) {
        if(adj[i][idx] < guess) toRemove.push_back(i);
      }
    }
    for(auto i : toRemove) {
      adj[i][i] = -1;
    }
  }
public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    if(wordlist.size() < 11) {
      for(auto &s : wordlist) master.guess(s);
      return;
    }
    init(wordlist);
    for(int i = 0; i < 10; ++i) {
      int g = getNextGuess();
      int result = master.guess(wordlist[g]);
      // cout << g << ' ' << result << ' ' << wordlist[g] << endl;
      if(result == 6) break;
      pruneGuess(g, result);
    }
  }
};
// @lc code=end

