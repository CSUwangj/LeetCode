/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */

// @lc code=start
class TopVotedCandidate {
  vector<int> leading;
  vector<int> &_times;
  int len;
public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times): _times(times) {
    unordered_map<int, int> cnt;
    len = persons.size();
    leading.resize(len);
    int curMax = 0;
    int curLeading = -1;
    for(int i = 0; i < len; ++i) {
      cnt[persons[i]] += 1;
      if(cnt[persons[i]] >= curMax) {
        curMax = cnt[persons[i]];
        curLeading = persons[i];
      }
      leading[i] = curLeading;
    }
  }
  
  int q(int t) {
    int offset = upper_bound(_times.begin(), _times.end(), t) - _times.begin();
    return offset == len ? leading.back() : leading[offset - 1];
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

