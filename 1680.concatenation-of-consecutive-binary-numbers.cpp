/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution {
  const long long MOD = 1e9+7;
  long long pow(long long base, long long exp) {
    long long res = 1;
    while(exp) {
      if(exp & 1) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1;
    }
    return res;
  }
  vector<int> getB(int n, int len) {
    vector<int> result;
    for(int i = 0; i < len; ++i) result.push_back(1 << i);
    int rest = n - (1 << len) + 1;
    for(int i = len; i >= 0; --i) {
      if((rest & (1 << i))) result.push_back(1 << i);
    }
    return move(result);
  }
public:
  int concatenatedBinary(int n) {
    if(n == 1) return 1;
    int blen = log2(n) + 1;
    // cout << n << ' ' << blen << endl;
    
    vector<int> B = getB(n, blen-1);
    int len = B.size();
    vector<int> A(len);
    vector<int> C(len);
    vector<int> D(len);
    for(int i = 1; i < blen; ++i) C[i-1] = i;
    for(int i = blen-1; i < len; ++i) C[i] = blen;
    for(int i = 1; i < len; ++i) D[len-i-1] = D[len-i] + C[len-i]*B[len-i];
    A[0] = B[0];
    for(int i = 1; i < len; ++i) A[i] = B[i] + A[i-1];
    // for(int i = 0; i < len; ++i) {
    //   cout << A[i] << ' ' << B[i] << ' ' << C[i] << ' ' << D[i] << endl;
    // }
    // cout <<"@@@@@@@@@@@@@@@@@@@@@" << endl;
    long long answer = 0;
    for(int i = 0; i < len; ++i) {
      long long t1 = pow(2LL, B[i]*C[i]) - 1;
      long long t2 = pow(pow(2LL, C[i])-1, MOD-2);
      long long t3 = ((A[i]-B[i]+1+t2)*t1-B[i]) % MOD;
      answer += t2 * t3 % MOD * pow(2LL, D[i]);
      // cout << t1 << ' ' << t2 << ' ' << t3 << endl;
      answer %= MOD;
      // cout << answer << endl;
    }
    return answer;
  }
};

// Accepted
// 403/403 cases passed (12 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 19.02 % of cpp submissions (6.3 MB)
// @lc code=end

