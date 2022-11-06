/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
  const string chars = "ACGT";
public:
  int minMutation(string start, string end, vector<string>& bank) {
    if(start == end) return 0;
    set<string> valid(bank.begin(), bank.end());
    if(!valid.count(end)) return -1;
    valid.erase(start);
    queue<string> q;
    q.push(start);
    int step = 0;
    while(q.size()) {
      int sz = q.size();
      while(sz--) {
        auto current = q.front();
        q.pop();
        if(current == end) return step;
        for(auto &c : current) {
          int origin = c;
          for(auto mutation : chars) {
            c = mutation;
            if(!valid.count(current)) continue;
            valid.erase(current);
            q.push(current);
          }
          c = origin;
        }
      }
      step += 1;
    }
    return -1;
  }
};

// Accepted
// 15/15 cases passed (5 ms)
// Your runtime beats 18.63 % of cpp submissions
// Your memory usage beats 81.49 % of cpp submissions (6.5 MB)
// @lc code=end

