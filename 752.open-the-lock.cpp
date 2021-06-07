/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
  void checkAndInsert(
    unordered_map<string, int> &cnt,
    queue<string> &q,
    string &cur
  ) {
    int originalCnt = cnt[cur];
    for(auto &c : cur) {
      c = (c - '0' + 9) % 10 + '0';
      if(!cnt.count(cur)) {
        cnt[cur] = originalCnt + 1;
        q.push(cur);
      }
      c = (c - '0' + 2) % 10 + '0';
      if(!cnt.count(cur)) {
        cnt[cur] = originalCnt + 1;
        q.push(cur);
      }
      c = (c - '0' + 9) % 10 + '0';
    }
  }
public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if(dead.count("0000") || dead.count(target)) return -1;
    unordered_map<string, int> frontBFS{{"0000", 0}}, backBFS{{target, 0}};
    queue<string> frontQ, backQ;
    frontQ.push("0000");
    backQ.push(target);
    int cnt = 0;
    while(frontQ.size() && backQ.size()) {
      int frontSize = frontQ.size();
      for(int i = 0; i < frontSize; ++i) {
        auto cur = frontQ.front();
        frontQ.pop();
        if(backBFS.count(cur)) {
          return frontBFS[cur] + backBFS[cur];
        }
        checkAndInsert(frontBFS, frontQ, cur);
      }
      int backSize = backQ.size();
      for(int i = 0; i < backSize; ++i) {
        auto cur = backQ.front();
        backQ.pop();
        if(frontBFS.count(cur)) {
          return frontBFS[cur] + backBFS[cur];
        }
        checkAndInsert(backBFS, backQ, cur);
      }
    }
    return -1;
  }
};
// @lc code=end

