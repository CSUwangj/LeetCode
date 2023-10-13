/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < groupSizes.size(); ++i) {
      mp[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> answer;
    for(auto &[sz, people] : mp) {
      for(int i = 0; i * sz < people.size(); ++i) {
        vector<int> result;
        for(int j = 0; j < sz; ++j) {
          result.push_back(people[i * sz + j]);
        }
        answer.emplace_back(move(result));
      }
    }

    return answer;
  }
};

// Accepted
// 103/103 cases passed (11 ms)
// Your runtime beats 57.7 % of cpp submissions
// Your memory usage beats 46.45 % of cpp submissions (13.2 MB)
// @lc code=end

