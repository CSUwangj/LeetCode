/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
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
  int totalFruit(vector<int>& fruits) {
    map<int, int> count;
    int answer = 0;
    int current = 0;
    int left = 0;
    int right = 0;
    while(right < fruits.size()) {
      while(count.size() < 3 && right < fruits.size()) {
        count[fruits[right]] += 1;
        current += 1;
        right += 1;
      }
      answer = max(answer, current - (count.size() == 3));
      while(count.size() > 2) {
        count[fruits[left]] -= 1;
        if(!count[fruits[left]]) {
          count.erase(fruits[left]);
        }
        current -= 1;
        left += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 91/91 cases passed (171 ms)
// Your runtime beats 81.22 % of cpp submissions
// Your memory usage beats 5.78 % of cpp submissions (75.4 MB)
// @lc code=end

