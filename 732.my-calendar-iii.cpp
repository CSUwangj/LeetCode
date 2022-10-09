/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
  map<int, int> count;
public:
  MyCalendarThree() {  }
  
  int book(int start, int end) {
    count[start] += 1;
    count[end] -= 1;
    int answer = 0;
    int current = 0;
    for(const auto &[pos, cnt] : count) {
      current += cnt;
      answer = max(answer, current);
    }
    return answer;
  }
};

// Accepted
// 98/98 cases passed (292 ms)
// Your runtime beats 22.72 % of cpp submissions
// Your memory usage beats 94.41 % of cpp submissions (262.3 MB)
// @lc code=end

