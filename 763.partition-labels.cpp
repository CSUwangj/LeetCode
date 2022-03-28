/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<pair<int, int>> pos(26, {-1, -1});
    for(int i = 0; i < s.length(); ++i) {
      if(pos[s[i] - 'a'].first == -1) {
        pos[s[i] - 'a'].first = i;
      }
      pos[s[i] - 'a'].second = i;
    }
    sort(pos.begin(), pos.end());
    vector<int> answer;
    int begin = pos.front().first;
    int end = pos.front().second;
    for(auto [b, e] : pos) {
      if(b > end) {
        if(begin != -1) {
          answer.push_back(end - begin + 1);
        }
        begin = b;
        end = e;
      } else {
        end = max(end, e);
      }
    }
    answer.push_back(end - begin + 1);
    return answer;
  }
};

// Accepted
// 117/117 cases passed (3 ms)
// Your runtime beats 85.7 % of cpp submissions
// Your memory usage beats 64.08 % of cpp submissions (6.6 MB)
// @lc code=end
