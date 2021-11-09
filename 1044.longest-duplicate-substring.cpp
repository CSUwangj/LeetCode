/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring_view
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class rabinFingerprint {
public:
  size_t operator()(const string_view& s)
  {
    if (m_clear) {
      m_pow = 1;
      for (size_t i = 1; i != s.size(); ++i) {
        m_pow = (m_pow * base) % p;
      }
      m_cur = 0;
      for (auto c : s) {
        m_cur = ((m_cur * base) % p + (c - 'a')) % p;
      }
      m_clear = false;
    } else {
      m_cur = ((ssize_t(m_cur) - ssize_t(m_pow * (m_first - 'a'))) % ssize_t(p) + p) % p;
      m_cur = (m_cur * base + (s.back() - 'a')) % p;
    }
    m_first = s.front();
    return m_cur;
  };
  
  void clear() { m_clear = true; }

private:
  static constexpr size_t p = 19260817;
  static constexpr size_t base = 26;

  bool m_clear = true;
  size_t m_cur;
  size_t m_pow;
  char m_first;
};
struct wrapper {
  size_t operator()(const string_view& s) const {
    return m_hasher(s);
  }
  
  rabinFingerprint& m_hasher;  
};
class Solution {
public:
  string longestDupSubstring(string &s) {
    int len = s.length();
    rabinFingerprint hasher;
    unordered_set<string_view, wrapper> st{10, wrapper{hasher}};

    string_view answer;
    int low = 1;
    int high = len;
    while(low <= high) {
      int mid = (low + high) >> 1;
      bool found = false;
      for(int i = 0; i + mid <= len; ++ i) {
        const auto [it, inserted] = st.emplace(s.data() + i, mid);
        if(!inserted) {
          answer = *it;
          found = true;
          break;
        }
      }
      if(found) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
      
      st.clear();
      hasher.clear();
    }

    return {answer.begin(), answer.end()};
  }
};

// Accepted
// 66/66 cases passed (604 ms)
// Your runtime beats 91.95 % of cpp submissions
// Your memory usage beats 80.2 % of cpp submissions (167.4 MB)
// @lc code=end

