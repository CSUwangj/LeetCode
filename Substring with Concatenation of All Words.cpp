// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<int> kmpNext;
  void initNext(string &s) {
    kmpNext.clear();
    kmpNext.push_back(-1);
    int cur = 0;
    int len = s.length();
    for(int i = 1; i < len; ++i) {
      if(cur >= 0 && s[i] == s[cur]) {
        kmpNext.push_back(kmpNext[cur]);
      } else {
        kmpNext.push_back(cur);
        do {
          cur = kmpNext[cur];
        } while(cur >= 0 && s[i] != s[cur]);
      }
      cur += 1;
    }
    kmpNext.push_back(cur);
  }
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int amount = words.size();
    int len = words[0].length();
    int slen = s.length();
    map<string, int> cnt;
    map<int, string> invertedIndex;
    for(auto &word : words) {
      if(!cnt.count(word)) {
        initNext(word);
        int cur = 0;
        int j = 0;
        while(j < slen) {
          if(s[j] == word[cur]) {
            j += 1;
            cur += 1;
            if(cur == len) {
              invertedIndex[j-cur] = word;
              cur = kmpNext[cur];
            }
          } else {
            cur = kmpNext[cur];
            if(cur < 0) {
              j += 1;
              cur += 1;
            }
          }
        }
      }
      cnt[word] += 1;
    }
    vector<int> answer;
    for(auto &[pos, word] : invertedIndex) {
      if(pos + amount*len > slen) break;
      auto curCnt = cnt;
      int curPos = pos + len;
      curCnt[word] -= 1;
      int rest = amount - 1;
      while(rest && invertedIndex.count(curPos) && curCnt[invertedIndex[curPos]]) {
        curCnt[invertedIndex[curPos]] -= 1;
        rest -= 1;
        curPos += len;
      }
      if(!rest) answer.push_back(pos);
    }
    return answer;
  }
};

int main() {
  vector<pair<string, vector<string>>> data = {
    // {"", {"aaaaa"}},
    // {"barfoothefoobarman", {"foo","bar"}},
    // {"barfoofoobarthefoobarman", {"bar","foo","the"}},
    // {"wordgoodgoodgoodbestword", {"word","good","best","word"}},
    {"wordgoodgoodgoodbestword", {"word","good","best","good"}},
    // {"ababaab", {"ab","ba","ba"}}
  };
  for(auto &[s, words]: data) {
    auto sol = Solution();
    auto ans = sol.findSubstring(s, words);
    cout << '[';
    for(auto i : ans) {
      cout << i << ", ";
    }
    cout << ']' << endl;
  } 
  return 0;
}