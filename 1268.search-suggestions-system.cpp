/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> answer;
    auto begin = products.begin();
    auto end = products.end();
    for(int i = 0; i < searchWord.length(); ++i) {
      auto cmp = [=](string a, string b) {
        return a[i] < b[i];
      };
      auto newBegin = lower_bound(begin, end, searchWord, cmp);
      auto newEnd = upper_bound(begin, end, searchWord, cmp);
      begin = newBegin;
      end = newEnd;
      if(newEnd - newBegin > 3) newEnd = newBegin + 3;
      if(newEnd - newBegin <= 0) break;
      answer.push_back(vector<string>(newBegin, newEnd));
    }
    while(answer.size() < searchWord.length()) answer.push_back({});
    return answer;
  }
};
// @lc code=end

