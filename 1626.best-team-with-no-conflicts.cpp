/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    vector<pair<int, int>> players;
    for(int i = 0; i < scores.size(); ++i) {
      players.push_back({scores[i], ages[i]});
    }
    sort(players.begin(), players.end());

    map<int, int> result{{0, 0}};
    for(const auto &[score, age] : players) {
      auto it = result.upper_bound(age);
      --it; // less or equal
      int scoreSum = score + it->second;
      auto insertPos = result.insert(it, {age, scoreSum});
      if(insertPos->second < scoreSum) {
        insertPos->second = scoreSum;
      }
      ++insertPos;
      while(insertPos != result.end() && insertPos->second <= scoreSum) {
        result.erase(insertPos++);
      }
    }

    return result.rbegin()->second;
  }
};

// Accepted
// 149/149 cases passed (41 ms)
// Your runtime beats 99.03 % of cpp submissions
// Your memory usage beats 40.91 % of cpp submissions (22.4 MB)
// @lc code=end

