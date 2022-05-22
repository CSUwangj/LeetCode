/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
constexpr int MOD = 4001;
class MyHashSet {
  vector<vector<int>> container;
public:
  MyHashSet(): container(MOD) {}
  
  void add(int key) {
    int val = key;
    key %= MOD;
    for(auto v : container[key]) {
      if(v == val) return;
    }
    container[key].push_back(val);
  }
  
  void remove(int key) {
    int val = key;
    key %= MOD;
    auto it = container[key].begin();
    while(it != container[key].end() && *it != val) {
      ++it;
    }
    if(it != container[key].end()) {
      container[key].erase(it);
    }
  }
  
  bool contains(int key) {
    int val = key;
    key %= MOD;
    for(auto v : container[key]) {
      if(v == val) return true;
    }
    return false;
  }
};

// Accepted
// 32/32 cases passed (93 ms)
// Your runtime beats 87.94 % of cpp submissions
// Your memory usage beats 39.75 % of cpp submissions (43.9 MB)
// @lc code=end

