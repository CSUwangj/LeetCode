/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> s;
    s.push_back(asteroids[0]);
    for(int i = 1; i < asteroids.size(); ++i) {
      if(s.empty() || s.back() < 0) {
        s.push_back(asteroids[i]);
        continue;
      }
      if(asteroids[i] > 0) {
        s.push_back(asteroids[i]);
        continue;
      }
      while(s.size() && s.back() > 0 && -asteroids[i] > s.back()) s.pop_back();
      if(s.empty() || s.back() < 0) s.push_back(asteroids[i]);
      else if(s.size() && -asteroids[i] == s.back()) s.pop_back();
    }
    return s;
  }
};

// Accepted
// 275/275 cases passed (15 ms)
// Your runtime beats 71.71 % of cpp submissions
// Your memory usage beats 81.53 % of cpp submissions (17.5 MB)
// @lc code=end

