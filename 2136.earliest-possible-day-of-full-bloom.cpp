/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Process Restricted Friend Requests
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    vector<pair<int, int>> plant;
    for(int i = 0; i < plantTime.size(); ++i) {
      plant.push_back({growTime[i], plantTime[i]});
    }
    sort(plant.begin(), plant.end());
    int answer = 0;
    for(auto [growTime, plantTime] : plant) {
      answer = max(answer, growTime) + plantTime;
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (479 ms)
// Your runtime beats 77.91 % of cpp submissions
// Your memory usage beats 62.85 % of cpp submissions (168.2 MB)
// @lc code=end

