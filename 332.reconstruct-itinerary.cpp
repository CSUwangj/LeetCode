/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
  int target = 0;
  void solve(
    const string &current,
    vector<string> &answer,
    map<string, vector<string>> &neighbors
  ) {
    while(neighbors[current].size()) {
      string next = neighbors[current].back();
      neighbors[current].pop_back();
      solve(next, answer, neighbors);
    }
    answer.push_back(current);
  }
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    target = tickets.size() + 1;
    map<string, vector<string>> neighbors;
    for(const auto &ticket : tickets) {
      neighbors[ticket[0]].push_back(ticket[1]);
    }
    for(auto &[from, tos] : neighbors) {
      sort(tos.rbegin(), tos.rend());
    }

    vector<string> answer;
    solve("JFK", answer, neighbors);
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 80/80 cases passed (14 ms)
// Your runtime beats 92.9 % of cpp submissions
// Your memory usage beats 63.46 % of cpp submissions (14.4 MB)
// @lc code=end

