/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    vector<pair<int, int>> cr;
    for(auto &c : courses) cr.push_back(make_pair(c[1], c[0]));
    sort(cr.begin(), cr.end());
    priority_queue<int> q;
    int cur = 0;
    for(auto &[ddl, duration] : cr) {
      if(cur + duration <= ddl) {
        q.push(duration);
        cur += duration;
      } else if(q.size() && q.top() > duration) {
        cur += duration - q.top();
        q.pop();
        q.push(duration);
      }
    }
    return q.size();
  }
};

// Accepted
// 97/97 cases passed (164 ms)
// Your runtime beats 98.56 % of cpp submissions
// Your memory usage beats 50.48 % of cpp submissions (60.7 MB)
// @lc code=end

