#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pari(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  bool isPrefixOfIndex(const int offset, const string& prefix, const string& str) {
    for (int i = 0; i < prefix.length(); ++i) {
      if (prefix[i] != str[offset + i]) {
        return false;
      }
    }
    return true;
  }
  int isPrefixOfWord(string sentence, string searchWord) {
    int count = 0;
    for (int i = 0; i <= int(sentence.length()) - int(searchWord.length()); ++i) {
      if (sentence[i] == ' ') {
        count += 1;
      } else if (!i || sentence[i - 1] == ' ') {
        if (isPrefixOfIndex(i, searchWord, sentence)) {
          return count + 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  string data[5][2] = {
    // { "this problem is an easy problem", "pro" },
    // { "i love eating burger", "burg" },
    // { "i am tired", "you" },
    // { "i use triple pillow", "pill" },
    // { "hello from the other side", "they" },
    {"i dumb", "jiezcqu"}
  };
  for(auto &data: data) {
    auto sol = Solution();
    int ans = sol.isPrefixOfWord(data[0], data[1]);
    cout << ans << endl;
  } 
  return 0;
}