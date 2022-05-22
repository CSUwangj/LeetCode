/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */

// @lc code=start
const int MOD = 1e9 + 7;
constexpr int pick(int total, int need) {
  if(total < need) return 0;
  long long answer = 1;
  for(int i = 1; i <= need; ++i) {
    answer *= (total + 1 - i);
    answer /= i;
    answer %= MOD;
  }
  return answer;
}

class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    map<int, int> count;
    for(auto num : arr) count[num] += 1;
    
    long long answer = 0;
    for(auto it = count.begin(); it != count.end(); ++it) {
      for(auto jt = it; jt != count.end(); ++jt) {
        int rest = target - it->first - jt->first;
        if(rest < jt->first || !count.count(rest)) continue;
        if(it->first == jt->first && it->first == rest) {
          answer += pick(it->second, 3);
        } else if(it->first == jt->first) {
          answer += pick(it->second, 2) * count[rest];
        } else if(jt->first == rest) {
          answer += pick(jt->second, 2) * it->second;
        } else {
          answer += it->second * jt->second * count[rest];
        }
        answer %= MOD;
      }
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (12 ms)
// Your runtime beats 92.78 % of cpp submissions
// Your memory usage beats 62.54 % of cpp submissions (10.6 MB)
// @lc code=end
