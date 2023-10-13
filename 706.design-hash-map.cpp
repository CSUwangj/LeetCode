/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int MOD = 4001;
class MyHashMap {
  vector<vector<pair<int, int>>> container;
public:
  /** Initialize your data structure here. */
  MyHashMap(): container(MOD) {}
  
  /** value will always be non-negative. */
  void put(int key, int value) {
    int val = key;
    key %= MOD;
    for(auto &[k, v] : container[key]) {
      if(k == val) {
        v = value;
        return;
      }
    }
    container[key].push_back({val, value});
  }
  
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    int val = key;
    key %= MOD;
    for(auto [k, v] : container[key]) {
      if(k == val) return v;
    }
    return -1;
  }
  
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    int val = key;
    key %= MOD;
    auto it = container[key].begin();
    while(it != container[key].end() && it->first != val) {
      ++it;
    }
    if(it != container[key].end()) {
      container[key].erase(it);
    }
  }
};

// Accepted
// 36/36 cases passed (95 ms)
// Your runtime beats 92.1 % of cpp submissions
// Your memory usage beats 59.66 % of cpp submissions (55.2 MB)
// @lc code=end

