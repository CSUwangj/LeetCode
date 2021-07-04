/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int len = people.size();
    if(people.back() * 2 <= limit) return (len + 1) / 2;
    if(people.front() * 2 > limit) return len;
    int ed = len - 1;
    int st = 0;
    int answer = 0;
    while(st < ed) {
      if(people[st] + people[ed] > limit) {
        ed -= 1;
      } else {
        ed -= 1;
        st += 1;
      }
      answer += 1;
    }
    answer += (st == ed);
    return answer;
  }
};
// @lc code=end

