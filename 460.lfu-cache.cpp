/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
  int capacity;
  int lowestFrequency = 0;
  unordered_map<int, int> kv;
  unordered_map<int, list<int>> freqList;
  unordered_map<int, int> frequencies;
  unordered_map<int, list<int>::iterator> pos;
  void updateFrequency(int key) {
    int frequency = frequencies[key];
    freqList[frequency].erase(pos[key]);
    if(freqList[lowestFrequency].empty()) {
      lowestFrequency += 1;
    }
    frequencies[key] += 1;
    freqList[frequency + 1].push_front(key);
    pos[key] = freqList[frequency + 1].begin();
  }
public:
  LFUCache(int cap): capacity(cap) {}
  
  int get(int key) {
    if(kv.count(key)) {
      updateFrequency(key);
      return kv[key];
    }
    return -1;
  }
  
  void put(int key, int value) {
    if(!capacity) return;
    if(kv.count(key)) {
      updateFrequency(key);
    } else {
      if(capacity == kv.size()) {
        int removedKey = freqList[lowestFrequency].back();
        // cout << "remove " << removedKey << endl; 
        kv.erase(removedKey);
        pos.erase(removedKey);
        freqList[lowestFrequency].pop_back();
      }
      freqList[0].push_front(key);
      pos[key] = freqList[0].begin();
      lowestFrequency = 0;
    }
    kv[key] = value;
  }
};

// Accepted
// 24/24 cases passed (476 ms)
// Your runtime beats 54.1 % of cpp submissions
// Your memory usage beats 53.17 % of cpp submissions (185.7 MB)
// @lc code=end

