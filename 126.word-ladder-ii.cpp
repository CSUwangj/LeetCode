/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, vector<string>> neighbor;
  unordered_set<string> vis;
  unordered_map<string, unordered_map<int, vector<vector<string>>>> cache;
  vector<vector<string>> transform(string beginWord, string endWord, int rest) {
    if(rest == 2) {
      return {{endWord, beginWord}};
    }
    if(cache[beginWord].count(rest)) return cache[beginWord][rest];
    vector<vector<string>> answer;
    for(auto &nxt : neighbor[beginWord]) {
      if(diff(nxt, endWord) > rest - 2 || vis.count(nxt)) continue;
      vis.insert(nxt);
      for(auto &result : transform(nxt, endWord, rest - 1)) {
        result.push_back(beginWord);
        answer.emplace_back(result);
      }
      vis.erase(nxt);
    }
    cache[beginWord][rest] = answer;
    return answer;
  }
  int diff(const string &a, const string &b) {
    int cnt = 0;
    for(int i = 0; i < a.length(); ++i) {
      cnt += a[i] != b[i];
    }
    return cnt;
  }
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int len = wordList.size();
    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
    // cout << "###########" << endl;
    for(auto &word : wordList) {
      if(diff(beginWord, word) == 1) neighbor[beginWord].push_back(word);
    }
    for(int i = 0; i < len - 1; ++i) {
      if(wordList[i] == beginWord) continue;
      for(int j = i + 1; j < len; ++j) {
        if(wordList[j] != beginWord && diff(wordList[i], wordList[j]) == 1) {
          neighbor[wordList[i]].push_back(wordList[j]);
          neighbor[wordList[j]].push_back(wordList[i]);
        }
      }
    }
    // for(auto [cur, n] : neighbor) {
    //   cout << cur << ' ' << n << endl;
    // }
    queue<string> q;
    vis.insert(beginWord);
    q.push(beginWord);
    int step = 0;
    int round = 0;
    for(int round = 1; !step && q.size(); ++round) {
      int sz = q.size();
      for(int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        if(cur == endWord) {
          step = round;
          break;
        }
        for(auto nxt : neighbor[cur]) {
          if(vis.count(nxt)) continue;
          vis.insert(nxt);
          q.push(nxt);
        }
      }
    }
    // cout << step << endl;
    if(!step) return {};
    vis.clear();
    vis.insert(beginWord);
    auto answer = transform(beginWord, endWord, step);
    for(auto &result : answer) {
      reverse(result.begin(), result.end());
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (144 ms)
// Your runtime beats 7.11 % of cpp submissions
// Your memory usage beats 9.2 % of cpp submissions (21.6 MB)
// @lc code=end

