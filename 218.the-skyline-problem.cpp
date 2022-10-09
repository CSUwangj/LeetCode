/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<tuple<int, int, int>> points;
    for(auto &b : buildings) {
      points.push_back(make_tuple(b[0], b[1], b[2]));
      points.push_back(make_tuple(b[1], -1, b[2]));
    }
    sort(points.begin(), points.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b){
      auto [al, ar, ah] = a;
      auto [bl, br, bh] = b;
      return al < bl || (al == bl && ((ar != -1 && br == -1) || (ar != -1 && br != -1 && ah > bh)));
    });
    int curHeight = 0;
    priority_queue<pair<int, int>> q;
    vector<vector<int>> answer;
    for(auto [curPos, rightPos, height] : points) {
      cout << curPos << ' ' << rightPos << ' ' << height << endl;
      if(rightPos == -1) {
        while(q.size() && q.top().second >= -curPos) cout << '#' << q.top().first << ' ' << q.top().second << endl, q.pop();
        int newHeight = q.size() ? q.top().first : 0;
        if(newHeight != curHeight) answer.push_back({curPos, newHeight});
        curHeight = newHeight;
      } else {
        q.push(make_pair(height, -rightPos));
        if(height > curHeight) {
          curHeight = height;
          answer.push_back({curPos, curHeight});
        }
      }
    }
    return answer;
  }
};

// Accepted
// 40/40 cases passed (157 ms)
// Your runtime beats 7.99 % of cpp submissions
// Your memory usage beats 82.66 % of cpp submissions (14.4 MB)
// @lc code=end

