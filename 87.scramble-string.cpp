/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
unordered_map<char, int> cnta;
unordered_map<char, int> cntb;
bool test(string &a, string &b, int sa, int ea, int sb, int eb) {
  // cout << a << ' ' << b << ' ' << sa << ' ' << ea << ' ' << sb << ' ' << eb << endl;
  cnta.clear();
  cntb.clear();
  int len = ea - sa;
  bool ok = true;
  for(int i = 0; i < len; ++i) {
    ok &= a[sa + i] == b[sb + i];
    cnta[a[sa + i]] += 1;
    cntb[b[sb + i]] += 1;
  }
  if(ok) return true;
  if(cnta != cntb) return false;
  cnta.clear();
  cntb.clear();
  int begin = -1;
  for(int i = 0; i < len - 1; ++i) {
    cnta[a[sa + i]] += 1;
    cntb[b[sb + i]] += 1;
    if(cnta == cntb) begin = i;
  }
  begin += 1;
  if(begin) return test(a, b, sa, sa + begin, sb, sb + begin) && test(a, b, sa + begin, ea, sb + begin, eb);
  int end = -1;
  cnta.clear();
  cntb.clear();
  for(int i = 0; i < len - 1; ++i) {
    cnta[a[sa + i]] += 1;
    cntb[b[eb - 1 - i]] += 1;
    if(cnta == cntb) end = i;
  }
  end += 1;
  if(end) return test(a, b, sa, sa + end, eb - end, eb) && test(a, b, sa + end, ea, sb, sb + len - end);
  return false;
}

class Solution {
public:
  bool isScramble(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    if(len1 != len2) return false;
    return test(a, b, 0, len1, 0, len2);
  }
};
// @lc code=end

