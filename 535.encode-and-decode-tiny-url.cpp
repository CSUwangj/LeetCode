/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
public:
  unordered_map<string, string> mp;
  unordered_map<string, string> rmp;
  int count = 0;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if(!mp.count(longUrl)) {
      string cnt = to_string(count++);
      mp[longUrl] = cnt;
      rmp[cnt] = longUrl;
    }
    return mp[longUrl];
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return rmp[shortUrl];
  }
};

// Accepted
// 739/739 cases passed (6 ms)
// Your runtime beats 44.57 % of cpp submissions
// Your memory usage beats 16.54 % of cpp submissions (7.4 MB)
// @lc code=end

