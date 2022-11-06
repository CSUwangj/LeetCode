/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
  using psi = pair<string, int>;
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> count;
    for(const auto &word : words) {
      count[word] += 1;
    }
    vector<psi> container(count.begin(), count.end());
    sort(container.begin(), container.end(), [](const psi &a, const psi &b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    vector<string> answer;
    transform(container.begin(), container.begin() + k, back_inserter(answer), [](const psi &a) {
      return a.first;
    });
    return move(answer);
  }
};

// Accepted
// 110/110 cases passed (15 ms)
// Your runtime beats 85.73 % of cpp submissions
// Your memory usage beats 88.37 % of cpp submissions (12.5 MB)
// @lc code=end

