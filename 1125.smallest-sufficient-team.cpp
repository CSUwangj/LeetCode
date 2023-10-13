/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void solve(
    int skill,
    int mask,
    const vector<vector<int>> &peopleWithSkill,
    const vector<int> &peopleMask,
    vector<int> &current,
    vector<int> &answer
  ) {
    if(skill == peopleWithSkill.size()) {
      if(answer.empty() || current.size() < answer.size()) {
        answer = current;
      }
      return;
    }
    if((1 << skill) & mask) {
      solve(skill + 1, mask, peopleWithSkill, peopleMask, current, answer);
      return;
    }
    for(int i = 0; i < peopleWithSkill[skill].size(); ++i) {
      int newMask = mask | peopleMask[peopleWithSkill[skill][i]];
      current.push_back(peopleWithSkill[skill][i]);
      solve(skill + 1, newMask, peopleWithSkill, peopleMask, current, answer);
      current.pop_back();
    }
  }
public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    map<string, int> mp;
    for(int i = 0; i < req_skills.size(); ++i) {
      mp[req_skills[i]] = i;
    }
    vector<int> peopleMask(people.size());
    vector<vector<int>> peopleWithSkill(req_skills.size());
    for(int i = 0; i < people.size(); ++i) {
      for(int j = 0; j < people[i].size(); ++j) {
        int skill = mp[people[i][j]];
        peopleMask[i] |= (1 << skill);
        peopleWithSkill[skill].push_back(i);
      }
    }

    vector<int> answer;
    vector<int> current;
    solve(0, 0, peopleWithSkill, peopleMask, current, answer);
    return answer;
  }
};

// Accepted
// 38/38 cases passed (376 ms)
// Your runtime beats 34.19 % of cpp submissions
// Your memory usage beats 97.42 % of cpp submissions (8.8 MB)
// @lc code=end

