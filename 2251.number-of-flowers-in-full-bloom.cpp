/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    map<int, int> flowersAbs;
    for(const auto &flower : flowers) {
      flowersAbs[flower[0]] += 1;
      flowersAbs[flower[1] + 1] -= 1;
    }
    vector<int> indice(people.size());
    for(int i = 1; i < people.size(); ++i) {
      indice[i] = i;
    }
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return people[a] < people[b];
    });
    vector<int> answer(people.size());

    auto it = flowersAbs.begin();
    int flower = 0;
    for(auto index : indice) {
      while(it != flowersAbs.end() && it->first <= people[index]) {
        flower += it->second;
        ++it;
      }
      answer[index] = flower;
    }

    return answer;
  }
};

// Accepted
// 52/52 cases passed (284 ms)
// Your runtime beats 31.94 % of cpp submissions
// Your memory usage beats 60.07 % of cpp submissions (87 MB)
// @lc code=end

