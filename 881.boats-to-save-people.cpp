/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
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


// Accepted
// 78/78 cases passed (68 ms)
// Your runtime beats 97.18 % of cpp submissions
// Your memory usage beats 57.42 % of cpp submissions (42 MB)
// @lc code=end

