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
class MyHashMap {
  vector<int> table;
public:
  /** Initialize your data structure here. */
  MyHashMap() {
    table.resize(1000001, -1);
  }
  
  /** value will always be non-negative. */
  void put(int key, int value) {
    table[key] = value;
  }
  
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    return table[key];
  }
  
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    table[key] = -1;
  }
};

// Accepted
// 36/36 cases passed (152 ms)
// Your runtime beats 72.56 % of cpp submissions
// Your memory usage beats 14.49 % of cpp submissions (208.2 MB)
// @lc code=end

