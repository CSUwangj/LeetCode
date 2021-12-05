/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
struct SAMState {
  int len;
  int link;
  int next[26] = {};
};
SAMState SAM[4000];
class StreamChecker {
  int sz;
  int last;
  vector<string> words;
  void extend(char c) {
    // cout << char(c + 'a') << ' ';
    int cur = sz;
    sz += 1;
    SAM[cur].len = SAM[last].len + 1;
    int p = last;
    while(p != -1 && !SAM[p].next[c]) {
      SAM[p].next[c] = cur;
      p = SAM[p].link;
    }
    if(p == -1) {
      SAM[cur].link = 0;
    } else {
      int q = SAM[p].next[c];
      if(SAM[p].len + 1 == SAM[q].len) {
        SAM[cur].link = q;
      } else {
        int clone = sz;
        sz += 1;
        SAM[clone].len = SAM[p].len + 1;
        SAM[clone].link = SAM[p].link;
        for(int i = 0; i < 26; ++i) {
          SAM[clone].next[i] = SAM[p].next[i];
        }
        while(p != -1 && SAM[p].next[c] == q) {
          SAM[p].next[c] = clone;
          p = SAM[p].link;
        }
        SAM[q].link = clone;
        SAM[cur].link = clone;
      }
    }
    last = cur;
    // cout << "success" << endl;
  }
  bool query() {
    set<int> ends;
    int end = last;
    while(end != -1) {
      ends.insert(end);
      end = SAM[end].link;
    }
    for(auto &word : words) {
      int cur = 0;
      bool ok = true;
      for(auto c : word) {
        c -= 'a';
        cur = SAM[cur].next[c];
        if(!cur) {
          ok = false;
          break;
        }
      }
      if(ok && ends.count(cur)) {
        cout << sz << ' ' << word << endl;
        return true;
      }
    }
    return false;
  }
public:
  StreamChecker(vector<string>& words): words(words) {
    memset(SAM, 0, sizeof(SAM));
    SAM[0].link = -1;
    sz = 1;
    last = 0;
  }
  
  bool query(char letter) {
    extend(letter - 'a');
    return query();
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(c);
 */
// @lc code=end
