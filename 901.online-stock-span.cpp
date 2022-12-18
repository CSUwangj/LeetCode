/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class StockSpanner {
  vector<pair<int, int>> container;
public:
  StockSpanner() { }
    
  int next(int price) {
    if(container.empty() || container.back().first > price) {
      container.push_back({price, 1});
    } else {
      container.back().first = price;
      container.back().second += 1;
      while(container.size() > 1 && container.back().first >= container[container.size() - 2].first) {
        // cout << container.back().first << ' ' << container.back().second << endl;
        container[container.size() - 2].first = container.back().first;
        container[container.size() - 2].second += container.back().second;
        container.pop_back();
      }
    }
    return container.back().second;
  }
};

// Accepted
// 99/99 cases passed (318 ms)
// Your runtime beats 77.79 % of cpp submissions
// Your memory usage beats 98.88 % of cpp submissions (84.1 MB)
// @lc code=end

