/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
  vector<bool> container;
public:
  MyHashSet(): container(1000001) {}
  
  void add(int key) {
    container[key] = true;
  }
  
  void remove(int key) {
    container[key] = false;
  }
  
  bool contains(int key) {
    return container[key];
  }
};

// Accepted
// 32/32 cases passed (99 ms)
// Your runtime beats 83.06 % of cpp submissions
// Your memory usage beats 43.79 % of cpp submissions (43.6 MB)
// @lc code=end

