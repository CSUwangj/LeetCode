/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    });
    // cout << "#######" << endl;
    priority_queue<int> q;
    int cur = 0;
    int answer = 0;
    for(auto &course : courses) {
      // cout << cur << endl;
      if(cur + course[0] <= course[1]) {
        answer += 1;
        cur += course[0];
        q.push(course[0]);
      } else if(q.size() && q.top() > course[0]) {
        cur += course[0] - q.top();
        q.pop();
        q.push(course[0]);
      }
    }
    return answer;
  }
};

// Accepted
// 97/97 cases passed (204 ms)
// Your runtime beats 79.9 % of cpp submissions
// Your memory usage beats 85.17 % of cpp submissions (56.2 MB)

// @lc code=end

