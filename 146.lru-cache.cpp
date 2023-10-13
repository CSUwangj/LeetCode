/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
  int capacity;
  list<int> LRU;
  unordered_map<int, int> kv;
  unordered_map<int, list<int>::iterator> position;
  
  void update(int key) {
    LRU.erase(position[key]);
    add(key);
  }
  
  void add(int key) {
    LRU.push_front(key);
    position[key] = LRU.begin();
  }
  
  void evict_last() {
    kv.erase(LRU.back());
    position.erase(LRU.back());
    LRU.pop_back(); 
  }
public:
  LRUCache(int capacity) : capacity(capacity) {}
  
  int get(int key) {
    if(kv.count(key)) {
      update(key);
      return kv[key];
    }
    return -1;
  }
  
  void put(int key, int value) {
    if(kv.count(key)) {
      update(key);
    } else {
      if(LRU.size() == capacity) evict_last();
      add(key);
    }
    kv[key] = value;
  }
};

// Accepted
// 22/22 cases passed (538 ms)
// Your runtime beats 27.06 % of cpp submissions
// Your memory usage beats 41.51 % of cpp submissions (175.8 MB)
// @lc code=end

