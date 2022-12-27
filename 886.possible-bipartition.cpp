/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
  vector<vector<int>> dislike;
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikePairs) {
    dislike.resize(N+1);
    
    for(auto &pair : dislikePairs) {
      dislike[pair[0]].push_back(pair[1]);
      dislike[pair[1]].push_back(pair[0]);
    }
    
    vector<int> group(N+1, -1);
    while(true) {
      queue<int> q;
      for(int i = 1; i <= N; ++i) {
        if(group[i] == -1) {
          q.push(i);
          group[i] = 0;
          break;
        }
      }
      if(q.empty()) break;
      while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(auto dis : dislike[current]) {
          if(group[dis] != -1 && group[dis] == group[current]) return false;
          if(group[dis] == -1) q.push(dis);
          group[dis] = group[current] ^ 1;
        }
      }
    }
    return true;
  }
};

// Accepted
// 70/70 cases passed (472 ms)
// Your runtime beats 40.43 % of cpp submissions
// Your memory usage beats 75.45 % of cpp submissions (64.7 MB)
// @lc code=end

