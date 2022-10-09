/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class TimeMap {
  unordered_map<string, map<int, string, std::greater<int>>> container;
public:
  TimeMap() {}
  
  void set(string key, string value, int timestamp) {
    container[key][timestamp] = value;
  }
  
  string get(string key, int timestamp) {
    if(!container.count(key)) return "";
    auto it = container[key].lower_bound(timestamp);
    if(it == container[key].end()) return "";
    return it->second;
  }
};

// Accepted
// 48/48 cases passed (618 ms)
// Your runtime beats 49.72 % of cpp submissions
// Your memory usage beats 6.52 % of cpp submissions (131.9 MB)
// @lc code=end

